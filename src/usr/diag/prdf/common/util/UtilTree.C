/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/UtilTree.C $                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2012              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#include "UtilTree.H"

namespace PRDF
{

UtilTree::defaultComparator UtilTree::defComparator;
UtilTree::defaultCleanup UtilTree::defCleanup;
UtilTree::defaultCopier UtilTree::defCopy;

void UtilTree::printTree()
{
    this->printTree(0,root);
};

UtilTree::UtilTree()
    : root(NULL), comp(&defComparator), clean(&defCleanup), copy(&defCopy)
{
};

UtilTree::~UtilTree()
{
    cleanTree(root);
    root = NULL;
};

void UtilTree::empty()
{
    cleanTree(root);
};

void UtilTree::cleanTree(Node * root)
{
    if (NULL == root)
        return;

    cleanTree(root->left);
    cleanTree(root->right);

    (*clean)(root->value);
    delete root;

    return;
};

void * UtilTree::peek() const
{
    if (NULL == root)
        return NULL;
    return root->value;
};

void * UtilTree::find(void * v) const
{
    return (NULL != find(v, root) ? (find(v, root)->value) : NULL);
};

UtilTree::Node * UtilTree::find(void * v, Node * t) const
{
    if (NULL == t)
        return NULL;

    if (0 == (*comp)(v, t->value))
        return t;

    return find(v, (-1 == (*comp)(v, t->value) ? t->left : t->right));
};

void UtilTree::insert(void * v)
{
    insert(v, root);
    while (NULL != root->parent)
        root = root->parent;
    if (Node::RED == root->color)
        root->color = Node::BLACK;
};

void UtilTree::insert(void * v, Node *& t)
{
    if (NULL == t)
    {
        t = new Node(v);
        t->color = Node::RED;
    }
    else if (0 == (*comp)(v, t->value))
    {
        (*clean)(t->value);
        t->value = v;
    }
    else
    {
        Node *& temp = (-1 == (*comp)(v, t->value) ? t->left : t->right);
        if (NULL == temp)
        {
            insert(v, temp);
            temp->parent = t;
            balance_i(temp);
        }
        else
        {
            insert(v, temp);
        }
    }
};


void UtilTree::balance_i(Node * t)
{
    if (NULL == t) // Hmm...
        ;
    else if (NULL == t->parent)        // root node, fix color.
        t->color = Node::BLACK;
    else if (Node::BLACK == t->parent->color) // parent black, leave alone.
        ;
    else        // parent red.
    {
        bool parentLeft = t->parent->parent->left == t->parent;
        bool meLeft = t->parent->left == t;

        if (parentLeft != meLeft) // rotate LR or RL case (from grandparent).
        {
            if (!meLeft) // right of parent.
            {
                if (t->left)
                    t->left->parent = t->parent;
                t->parent->right = t->left;
                t->left = t->parent;
                t->parent->parent->left = t;
                t->parent = t->parent->parent;
                t->left->parent = t;
                balance_i(t->left);
            }
            else // left of parent.
            {
                if (t->right)
                    t->right->parent = t->parent;
                t->parent->left = t->right;
                t->right = t->parent;
                t->parent->parent->right = t;
                t->parent = t->parent->parent;
                t->right->parent = t;
                balance_i(t->right);
            }
        }
        else
        {
            bool hasRedUncle = false;
            if ((parentLeft ? t->parent->parent->right
                            : t->parent->parent->left) != NULL)
            {
                if ((parentLeft ? t->parent->parent->right
                            : t->parent->parent->left)->color == Node::RED)
                {
                    hasRedUncle = true;
                }
            }

            if (hasRedUncle)
            {
                t->parent->color = Node::BLACK;
                (parentLeft ? t->parent->parent->right
                            : t->parent->parent->left)->color = Node::BLACK;
                t->parent->parent->color = Node::RED;
                balance_i(t->parent->parent);
            }
            else
            {
                t = t->parent;
                if (NULL != t->parent->parent)
                    parentLeft = t->parent->parent->left == t->parent;
                meLeft = t->parent->left == t;

                if (meLeft)
                {
                    if (t->right)
                        t->right->parent = t->parent;
                    t->parent->left = t->right;
                    t->right = t->parent;
                    if (NULL != t->parent->parent)
                        if (parentLeft)
                            t->parent->parent->left = t;
                        else
                            t->parent->parent->right = t;
                    t->parent = t->parent->parent;
                    t->right->parent = t;
                    t->color = Node::BLACK;
                    t->right->color = Node::RED;
                }
                else
                {
                    if (t->left)
                        t->left->parent = t->parent;
                    t->parent->right = t->left;
                    t->left = t->parent;
                    if (NULL != t->parent->parent)
                        if (parentLeft)
                            t->parent->parent->left = t;
                        else
                            t->parent->parent->right = t;
                    t->parent = t->parent->parent;
                    t->left->parent = t;
                    t->color = Node::BLACK;
                    t->left->color = Node::RED;
                }
            }
        }
    }
}

UtilTree::UtilTree(const UtilTree & i_copy)
{
    comp = i_copy.comp;
    clean = i_copy.clean;
    copy = i_copy.copy;

    if (NULL == i_copy.root)
        root = NULL;
    else
    {
        root = new Node(NULL);
        copyNode(root, i_copy.root, NULL);
    }
};

void UtilTree::copyNode(Node * i_dest, Node * const i_src, Node * i_parent)
{
    i_dest->parent = i_parent;
    i_dest->color = i_src->color;
    i_dest->value = (*copy)(i_src->value);
    if (NULL == i_src->left)
        i_dest->left = NULL;
    else
    {
        i_dest->left = new Node(NULL);
        copyNode(i_dest->left, i_src->left, i_dest);
    }
    if (NULL == i_src->right)
        i_dest->right = NULL;
    else
    {
        i_dest->right = new Node(NULL);
        copyNode(i_dest->right, i_src->right, i_dest);
    };
};

UtilTree::iterator & UtilTree::iterator::operator++()
{
    if (NULL == _cur)
        return *(this);

    if (NULL == _cur->right)
    {
        while (_cur != NULL)
        {
            if (NULL != _cur->parent)
                if (_cur == _cur->parent->right)
                    _cur = _cur->parent;
                else
                {
                    _cur = _cur->parent;
                    break;
                }
            else
                _cur = _cur->parent;
        }
    }
    else
    {
        _cur = _cur->right;
        while (NULL != _cur->left)
            _cur = _cur->left;
    }

    return *(this);
};

UtilTree::iterator & UtilTree::iterator::operator--()
{
    if (NULL == _cur)
        return *(this);

    if (NULL == _cur->left)
    {
        while (_cur != NULL)
        {
            if (NULL != _cur->parent)
                if (_cur == _cur->parent->left)
                    _cur = _cur->parent;
                else
                {
                    _cur = _cur->parent;
                    break;
                }
            else
                _cur = _cur->parent;
        }
    }
    else
    {
        _cur = _cur->left;
        while (NULL != _cur->right)
            _cur = _cur->right;
    }

    return *(this);
};

UtilTree::iterator UtilTree::begin() const
{
    if (NULL == root)
        return end();

    Node * tmp = root;
    while (NULL != tmp->left)
        tmp = tmp->left;

    return iterator(tmp, this);
};

} // end namespace PRDF

