/**
 *  Contains constants needed for the Resource Providers
 */
namespace RP
{
    /**
     * Message IDs
     */
    enum Messages
    {
        /**
         * Read 1 page of data from the RP
         *   data[0] = address to copy into (user buffer)
         *   data[1] = address to copy from (effective address)
         */
        READ_PAGE, 

        /**
         * Write 1 page of data from the RP
         *   data[0] = address to copy from (user buffer)
         *   data[1] = address to copy into (effective address)
         */
        WRITE_PAGE, 
    };


};
