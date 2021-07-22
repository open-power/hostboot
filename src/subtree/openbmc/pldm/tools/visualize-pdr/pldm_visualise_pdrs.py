#!/usr/bin/env python3

"""Tool to visualize PLDM PDR's"""

import argparse
import json
import hashlib
import sys
from datetime import datetime
import paramiko
from graphviz import Digraph
from tabulate import tabulate


def connect_to_bmc(hostname, uname, passwd, port):

    """ This function is responsible to connect to the BMC via
        ssh and returns a client object.

        Parameters:
            hostname: hostname/IP address of BMC
            uname: ssh username of BMC
            passwd: ssh password of BMC
            port: ssh port of BMC

    """

    client = paramiko.SSHClient()
    client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    client.connect(hostname, username=uname, password=passwd, port=port)
    return client


def prepare_summary_report(state_sensor_pdr, state_effecter_pdr):

    """ This function is responsible to parse the state sensor pdr
        and the state effecter pdr dictionaries and creating the
        summary table.

        Parameters:
            state_sensor_pdr: list of state sensor pdrs
            state_effecter_pdr: list of state effecter pdrs

    """

    summary_table = []
    headers = ["sensor_id", "entity_type", "state_set", "states"]
    summary_table.append(headers)
    for value in state_sensor_pdr.values():
        summary_record = []
        sensor_possible_states = ''
        for sensor_state in value["possibleStates[0]"]:
            sensor_possible_states += sensor_state+"\n"
        summary_record.extend([value["sensorID"], value["entityType"],
                               value["stateSetID[0]"],
                               sensor_possible_states])
        summary_table.append(summary_record)
    print("Created at : ", datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
    print(tabulate(summary_table, tablefmt="fancy_grid", headers="firstrow"))

    summary_table = []
    headers = ["effecter_id", "entity_type", "state_set", "states"]
    summary_table.append(headers)
    for value in state_effecter_pdr.values():
        summary_record = []
        effecter_possible_states = ''
        for state in value["possibleStates[0]"]:
            effecter_possible_states += state+"\n"
        summary_record.extend([value["effecterID"], value["entityType"],
                               value["stateSetID[0]"],
                               effecter_possible_states])
        summary_table.append(summary_record)
    print(tabulate(summary_table, tablefmt="fancy_grid", headers="firstrow"))


def draw_entity_associations(pdr, counter):

    """ This function is responsible to create a picture that captures
        the entity association hierarchy based on the entity association
        PDR's received from the BMC.

        Parameters:
            pdr: list of entity association PDR's
            counter: variable to capture the count of PDR's to unflatten
                     the tree

    """

    dot = Digraph('entity_hierarchy', node_attr={'color': 'lightblue1',
                                                 'style': 'filled'})
    dot.attr(label=r'\n\nEntity Relation Diagram < ' +
             str(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))+'>\n')
    dot.attr(fontsize='20')
    edge_list = []
    for value in pdr.values():
        parentnode = str(value["containerEntityType"]) + \
                     str(value["containerEntityInstanceNumber"])
        dot.node(hashlib.md5((parentnode +
                              str(value["containerEntityContainerID"]))
                             .encode()).hexdigest(), parentnode)

        for i in range(1, value["containedEntityCount"]+1):
            childnode = str(value[f"containedEntityType[{i}]"]) + \
                        str(value[f"containedEntityInstanceNumber[{i}]"])
            cid = str(value[f"containedEntityContainerID[{i}]"])
            dot.node(hashlib.md5((childnode + cid)
                                 .encode()).hexdigest(), childnode)

            if[hashlib.md5((parentnode +
                            str(value["containerEntityContainerID"]))
                           .encode()).hexdigest(),
               hashlib.md5((childnode + cid)
                           .encode()).hexdigest()] not in edge_list:
                edge_list.append([hashlib.md5((parentnode +
                                  str(value["containerEntityContainerID"]))
                                              .encode()).hexdigest(),
                                  hashlib.md5((childnode + cid)
                                              .encode()).hexdigest()])
                dot.edge(hashlib.md5((parentnode +
                                      str(value["containerEntityContainerID"]))
                                     .encode()).hexdigest(),
                         hashlib.md5((childnode + cid).encode()).hexdigest())
    unflattentree = dot.unflatten(stagger=(round(counter/3)))
    unflattentree.render(filename='entity_association_' +
                         str(datetime.now().strftime("%Y-%m-%d_%H-%M-%S")),
                         view=False, cleanup=True, format='pdf')


def fetch_pdrs_from_bmc(client):

    """ This is the core function that would use the existing ssh connection
        object to connect to BMC and fire the getPDR pldmtool command
        and it then agreegates the data received from all the calls into
        the respective dictionaries based on the PDR Type.

        Parameters:
            client: paramiko ssh client object

    """

    entity_association_pdr = {}
    state_sensor_pdr = {}
    state_effecter_pdr = {}
    state_effecter_pdr = {}
    numeric_pdr = {}
    fru_record_set_pdr = {}
    tl_pdr = {}
    handle_number = 0
    while True:
        my_str = ''
        command = 'pldmtool platform getpdr -d ' + str(handle_number)
        output = client.exec_command(command)
        for line in output[1]:
            my_str += line.strip('\n')
        my_dic = json.loads(my_str)
        sys.stdout.write("Fetching PDR's from BMC : %8d\r" % (handle_number))
        sys.stdout.flush()
        if my_dic["PDRType"] == "Entity Association PDR":
            entity_association_pdr[handle_number] = my_dic
        if my_dic["PDRType"] == "State Sensor PDR":
            state_sensor_pdr[handle_number] = my_dic
        if my_dic["PDRType"] == "State Effecter PDR":
            state_effecter_pdr[handle_number] = my_dic
        if my_dic["PDRType"] == "FRU Record Set PDR":
            fru_record_set_pdr[handle_number] = my_dic
        if my_dic["PDRType"] == "Terminus Locator PDR":
            tl_pdr[handle_number] = my_dic
        if my_dic["PDRType"] == "Numeric Effecter PDR":
            numeric_pdr[handle_number] = my_dic
        if not my_dic["nextRecordHandle"] == 0:
            handle_number = my_dic["nextRecordHandle"]
        else:
            break
    client.close()

    total_pdrs = len(entity_association_pdr.keys()) + len(tl_pdr.keys()) + \
        len(state_effecter_pdr.keys()) + len(numeric_pdr.keys()) + \
        len(state_sensor_pdr.keys()) + len(fru_record_set_pdr.keys())
    print("\nSuccessfully fetched " + str(total_pdrs) + " PDR\'s")
    print("Number of FRU Record PDR's : ", len(fru_record_set_pdr.keys()))
    print("Number of TerminusLocator PDR's : ", len(tl_pdr.keys()))
    print("Number of State Sensor PDR's : ", len(state_sensor_pdr.keys()))
    print("Number of State Effecter PDR's : ", len(state_effecter_pdr.keys()))
    print("Number of Numeric Effecter PDR's : ", len(numeric_pdr.keys()))
    print("Number of Entity Association PDR's : ",
          len(entity_association_pdr.keys()))
    return (entity_association_pdr, state_sensor_pdr,
            state_effecter_pdr, len(fru_record_set_pdr.keys()))


def main():

    """ Create a summary table capturing the information of all the PDR's
        from the BMC & also create a diagram that captures the entity
        association hierarchy."""

    parser = argparse.ArgumentParser(prog='pldm_visualise_pdrs.py')
    parser.add_argument('--bmc', type=str, required=True,
                        help="BMC IPAddress/BMC Hostname")
    parser.add_argument('--user', type=str, required=True,
                        help="BMC username")
    parser.add_argument('--password', type=str, required=True,
                        help="BMC Password")
    parser.add_argument('--port', type=int, help="BMC SSH port",
                        default=22)
    args = parser.parse_args()
    if args.bmc and args.password and args.user:
        client = connect_to_bmc(args.bmc, args.user, args.password, args.port)
        association_pdr, state_sensor_pdr, state_effecter_pdr, counter = \
            fetch_pdrs_from_bmc(client)
        draw_entity_associations(association_pdr, counter)
        prepare_summary_report(state_sensor_pdr, state_effecter_pdr)


if __name__ == "__main__":
    main()
