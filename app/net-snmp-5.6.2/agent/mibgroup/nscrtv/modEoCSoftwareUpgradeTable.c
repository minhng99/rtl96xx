/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 15999 2007-03-25 22:32:02Z dts12 $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "modEoCSoftwareUpgradeTable.h"

/** Initializes the modEoCSoftwareUpgradeTable module */
void
init_modEoCSoftwareUpgradeTable(void)
{
    /*
     * here we initialize all the tables we're planning on supporting 
     */
    initialize_table_modEoCSoftwareUpgradeTable();
}

# Determine the first/last column names

/** Initialize the modEoCSoftwareUpgradeTable table by defining its contents and how it's structured */
void
initialize_table_modEoCSoftwareUpgradeTable(void)
{
    static oid      modEoCSoftwareUpgradeTable_oid[] =
        { 1, 3, 6, 1, 4, 1, 17409, 2, 4, 4, 5 };
    size_t          modEoCSoftwareUpgradeTable_oid_len =
        OID_LENGTH(modEoCSoftwareUpgradeTable_oid);
    netsnmp_handler_registration *reg;
    netsnmp_iterator_info *iinfo;
    netsnmp_table_registration_info *table_info;

    reg =
        netsnmp_create_handler_registration("modEoCSoftwareUpgradeTable",
                                            modEoCSoftwareUpgradeTable_handler,
                                            modEoCSoftwareUpgradeTable_oid,
                                            modEoCSoftwareUpgradeTable_oid_len,
                                            HANDLER_CAN_RWRITE);

    table_info = SNMP_MALLOC_TYPEDEF(netsnmp_table_registration_info);
    netsnmp_table_helper_add_indexes(table_info, ASN_INTEGER,   /* index: modEoCSoftwareUpgradeCBATCardIndex */
                                     ASN_INTEGER,       /* index: modEoCSoftwareUpgradeCNUIndex */
                                     0);
    table_info->min_column = COLUMN_MODEOCSOFTWAREUPGRADECBATCARDINDEX;
    table_info->max_column = COLUMN_MODEOCSOFTWAREUPGRADERESULT;

    iinfo = SNMP_MALLOC_TYPEDEF(netsnmp_iterator_info);
    iinfo->get_first_data_point =
        modEoCSoftwareUpgradeTable_get_first_data_point;
    iinfo->get_next_data_point =
        modEoCSoftwareUpgradeTable_get_next_data_point;
    iinfo->table_reginfo = table_info;

    netsnmp_register_table_iterator(reg, iinfo);

    /*
     * Initialise the contents of the table here 
     */
}

    /*
     * Typical data structure for a row entry 
     */
struct modEoCSoftwareUpgradeTable_entry {
    /*
     * Index values 
     */
    long            modEoCSoftwareUpgradeCBATCardIndex;
    long            modEoCSoftwareUpgradeCNUIndex;

    /*
     * Column values 
     */
    long            modEoCSoftwareUpgradeCBATCardIndex;
    long            modEoCSoftwareUpgradeCNUIndex;
    char            modEoCSoftwareUpgradeMACAddress[NNN];
    size_t          modEoCSoftwareUpgradeMACAddress_len;
    char            old_modEoCSoftwareUpgradeMACAddress[NNN];
    size_t          old_modEoCSoftwareUpgradeMACAddress_len;
    long            modEoCSoftwareUpgradeDevType;
    long            old_modEoCSoftwareUpgradeDevType;
    char            modEoCSoftwareUpgradeFileName[NNN];
    size_t          modEoCSoftwareUpgradeFileName_len;
    char            old_modEoCSoftwareUpgradeFileName[NNN];
    size_t          old_modEoCSoftwareUpgradeFileName_len;
    long            modEoCSoftwareUpgradeProceed;
    long            old_modEoCSoftwareUpgradeProceed;
    long            modEoCSoftwareUpgradeResult;

    /*
     * Illustrate using a simple linked list 
     */
    int             valid;
    struct modEoCSoftwareUpgradeTable_entry *next;
};

struct modEoCSoftwareUpgradeTable_entry *modEoCSoftwareUpgradeTable_head;

/*
 * create a new row in the (unsorted) table 
 */
struct modEoCSoftwareUpgradeTable_entry *
modEoCSoftwareUpgradeTable_createEntry(long
                                       modEoCSoftwareUpgradeCBATCardIndex,
                                       long modEoCSoftwareUpgradeCNUIndex,)
{
    struct modEoCSoftwareUpgradeTable_entry *entry;

    entry = SNMP_MALLOC_TYPEDEF(struct modEoCSoftwareUpgradeTable_entry);
    if (!entry)
        return NULL;

    entry->modEoCSoftwareUpgradeCBATCardIndex =
        modEoCSoftwareUpgradeCBATCardIndex;
    entry->modEoCSoftwareUpgradeCNUIndex = modEoCSoftwareUpgradeCNUIndex;
    entry->next = modEoCSoftwareUpgradeTable_head;
    modEoCSoftwareUpgradeTable_head = entry;
    return entry;
}

/*
 * remove a row from the table 
 */
void
modEoCSoftwareUpgradeTable_removeEntry(struct
                                       modEoCSoftwareUpgradeTable_entry
                                       *entry)
{
    struct modEoCSoftwareUpgradeTable_entry *ptr, *prev;

    if (!entry)
        return;                 /* Nothing to remove */

    for (ptr = modEoCSoftwareUpgradeTable_head, prev = NULL;
         ptr != NULL; prev = ptr, ptr = ptr->next) {
        if (ptr == entry)
            break;
    }
    if (!ptr)
        return;                 /* Can't find it */

    if (prev == NULL)
        modEoCSoftwareUpgradeTable_head = ptr->next;
    else
        prev->next = ptr->next;

    SNMP_FREE(entry);           /* XXX - release any other internal resources */
}


/*
 * Example iterator hook routines - using 'get_next' to do most of the work 
 */
netsnmp_variable_list *
modEoCSoftwareUpgradeTable_get_first_data_point(void **my_loop_context,
                                                void **my_data_context,
                                                netsnmp_variable_list *
                                                put_index_data,
                                                netsnmp_iterator_info
                                                *mydata)
{
    *my_loop_context = modEoCSoftwareUpgradeTable_head;
    return modEoCSoftwareUpgradeTable_get_next_data_point(my_loop_context,
                                                          my_data_context,
                                                          put_index_data,
                                                          mydata);
}

netsnmp_variable_list *
modEoCSoftwareUpgradeTable_get_next_data_point(void **my_loop_context,
                                               void **my_data_context,
                                               netsnmp_variable_list *
                                               put_index_data,
                                               netsnmp_iterator_info
                                               *mydata)
{
    struct modEoCSoftwareUpgradeTable_entry *entry =
        (struct modEoCSoftwareUpgradeTable_entry *) *my_loop_context;
    netsnmp_variable_list *idx = put_index_data;

    if (entry) {
        snmp_set_var_typed_integer(idx, ASN_INTEGER,
                                   entry->
                                   modEoCSoftwareUpgradeCBATCardIndex);
        idx = idx->next_variable;
        snmp_set_var_typed_integer(idx, ASN_INTEGER,
                                   entry->modEoCSoftwareUpgradeCNUIndex);
        idx = idx->next_variable;
        *my_data_context = (void *) entry;
        *my_loop_context = (void *) entry->next;
        return put_index_data;
    } else {
        return NULL;
    }
}


/** handles requests for the modEoCSoftwareUpgradeTable table */
int
modEoCSoftwareUpgradeTable_handler(netsnmp_mib_handler *handler,
                                   netsnmp_handler_registration *reginfo,
                                   netsnmp_agent_request_info *reqinfo,
                                   netsnmp_request_info *requests)
{

    netsnmp_request_info *request;
    netsnmp_table_request_info *table_info;
    struct modEoCSoftwareUpgradeTable_entry *table_entry;

    switch (reqinfo->mode) {
        /*
         * Read-support (also covers GetNext requests)
         */
    case MODE_GET:
        for (request = requests; request; request = request->next) {
            table_entry = (struct modEoCSoftwareUpgradeTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);

            switch (table_info->colnum) {
            case COLUMN_MODEOCSOFTWAREUPGRADECBATCARDINDEX:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           modEoCSoftwareUpgradeCBATCardIndex);
                break;
            case COLUMN_MODEOCSOFTWAREUPGRADECNUINDEX:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           modEoCSoftwareUpgradeCNUIndex);
                break;
            case COLUMN_MODEOCSOFTWAREUPGRADEMACADDRESS:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_value(request->requestvb, ASN_OCTET_STR,
                                         (u_char *) table_entry->
                                         modEoCSoftwareUpgradeMACAddress,
                                         table_entry->
                                         modEoCSoftwareUpgradeMACAddress_len);
                break;
            case COLUMN_MODEOCSOFTWAREUPGRADEDEVTYPE:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           modEoCSoftwareUpgradeDevType);
                break;
            case COLUMN_MODEOCSOFTWAREUPGRADEFILENAME:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_value(request->requestvb, ASN_OCTET_STR,
                                         (u_char *) table_entry->
                                         modEoCSoftwareUpgradeFileName,
                                         table_entry->
                                         modEoCSoftwareUpgradeFileName_len);
                break;
            case COLUMN_MODEOCSOFTWAREUPGRADEPROCEED:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           modEoCSoftwareUpgradeProceed);
                break;
            case COLUMN_MODEOCSOFTWAREUPGRADERESULT:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           modEoCSoftwareUpgradeResult);
                break;
            default:
                netsnmp_set_request_error(reqinfo, request,
                                          SNMP_NOSUCHOBJECT);
                break;
            }
        }
        break;

        /*
         * Write-support
         */
    case MODE_SET_RESERVE1:
        for (request = requests; request; request = request->next) {
            table_entry = (struct modEoCSoftwareUpgradeTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);

            switch (table_info->colnum) {
            case COLUMN_MODEOCSOFTWAREUPGRADEMACADDRESS:
                /*
                 * or possiblc 'netsnmp_check_vb_type_and_size' 
                 */
                ret =
                    netsnmp_check_vb_type_and_max_size(request->requestvb,
                                                       ASN_OCTET_STR,
                                                       sizeof(table_entry->
                                                              modEoCSoftwareUpgradeMACAddress));
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
                break;
            case COLUMN_MODEOCSOFTWAREUPGRADEDEVTYPE:
                /*
                 * or possibly 'netsnmp_check_vb_int_range' 
                 */
                ret = netsnmp_check_vb_int(request->requestvb);
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
                break;
            case COLUMN_MODEOCSOFTWAREUPGRADEFILENAME:
                /*
                 * or possiblc 'netsnmp_check_vb_type_and_size' 
                 */
                ret =
                    netsnmp_check_vb_type_and_max_size(request->requestvb,
                                                       ASN_OCTET_STR,
                                                       sizeof(table_entry->
                                                              modEoCSoftwareUpgradeFileName));
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
                break;
            case COLUMN_MODEOCSOFTWAREUPGRADEPROCEED:
                /*
                 * or possibly 'netsnmp_check_vb_int_range' 
                 */
                ret = netsnmp_check_vb_int(request->requestvb);
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
                break;
            default:
                netsnmp_set_request_error(reqinfo, request,
                                          SNMP_ERR_NOTWRITABLE);
                return SNMP_ERR_NOERROR;
            }
        }
        break;

    case MODE_SET_RESERVE2:
        break;

    case MODE_SET_FREE:
        break;

    case MODE_SET_ACTION:
        for (request = requests; request; request = request->next) {
            table_entry = (struct modEoCSoftwareUpgradeTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);

            switch (table_info->colnum) {
            case COLUMN_MODEOCSOFTWAREUPGRADEMACADDRESS:
                memcpy(table_entry->old_modEoCSoftwareUpgradeMACAddress,
                       table_entry->modEoCSoftwareUpgradeMACAddress,
                       sizeof(table_entry->
                              modEoCSoftwareUpgradeMACAddress));
                table_entry->old_modEoCSoftwareUpgradeMACAddress_len =
                    table_entry->modEoCSoftwareUpgradeMACAddress_len;
                memset(table_entry->modEoCSoftwareUpgradeMACAddress, 0,
                       sizeof(table_entry->
                              modEoCSoftwareUpgradeMACAddress));
                memcpy(table_entry->modEoCSoftwareUpgradeMACAddress,
                       request->requestvb->val.string,
                       request->requestvb->val_len);
                table_entry->modEoCSoftwareUpgradeMACAddress_len =
                    request->requestvb->val_len;
                break;
            case COLUMN_MODEOCSOFTWAREUPGRADEDEVTYPE:
                table_entry->old_modEoCSoftwareUpgradeDevType =
                    table_entry->modEoCSoftwareUpgradeDevType;
                table_entry->modEoCSoftwareUpgradeDevType =
                    *request->requestvb->val.integer;
                break;
            case COLUMN_MODEOCSOFTWAREUPGRADEFILENAME:
                memcpy(table_entry->old_modEoCSoftwareUpgradeFileName,
                       table_entry->modEoCSoftwareUpgradeFileName,
                       sizeof(table_entry->modEoCSoftwareUpgradeFileName));
                table_entry->old_modEoCSoftwareUpgradeFileName_len =
                    table_entry->modEoCSoftwareUpgradeFileName_len;
                memset(table_entry->modEoCSoftwareUpgradeFileName, 0,
                       sizeof(table_entry->modEoCSoftwareUpgradeFileName));
                memcpy(table_entry->modEoCSoftwareUpgradeFileName,
                       request->requestvb->val.string,
                       request->requestvb->val_len);
                table_entry->modEoCSoftwareUpgradeFileName_len =
                    request->requestvb->val_len;
                break;
            case COLUMN_MODEOCSOFTWAREUPGRADEPROCEED:
                table_entry->old_modEoCSoftwareUpgradeProceed =
                    table_entry->modEoCSoftwareUpgradeProceed;
                table_entry->modEoCSoftwareUpgradeProceed =
                    *request->requestvb->val.integer;
                break;
            }
        }
        break;

    case MODE_SET_UNDO:
        for (request = requests; request; request = request->next) {
            table_entry = (struct modEoCSoftwareUpgradeTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);

            switch (table_info->colnum) {
            case COLUMN_MODEOCSOFTWAREUPGRADEMACADDRESS:
                memcpy(table_entry->modEoCSoftwareUpgradeMACAddress,
                       table_entry->old_modEoCSoftwareUpgradeMACAddress,
                       sizeof(table_entry->
                              modEoCSoftwareUpgradeMACAddress));
                memset(table_entry->old_modEoCSoftwareUpgradeMACAddress, 0,
                       sizeof(table_entry->
                              modEoCSoftwareUpgradeMACAddress));
                table_entry->modEoCSoftwareUpgradeMACAddress_len =
                    table_entry->old_modEoCSoftwareUpgradeMACAddress_len;
                break;
            case COLUMN_MODEOCSOFTWAREUPGRADEDEVTYPE:
                table_entry->modEoCSoftwareUpgradeDevType =
                    table_entry->old_modEoCSoftwareUpgradeDevType;
                table_entry->old_modEoCSoftwareUpgradeDevType = 0;
                break;
            case COLUMN_MODEOCSOFTWAREUPGRADEFILENAME:
                memcpy(table_entry->modEoCSoftwareUpgradeFileName,
                       table_entry->old_modEoCSoftwareUpgradeFileName,
                       sizeof(table_entry->modEoCSoftwareUpgradeFileName));
                memset(table_entry->old_modEoCSoftwareUpgradeFileName, 0,
                       sizeof(table_entry->modEoCSoftwareUpgradeFileName));
                table_entry->modEoCSoftwareUpgradeFileName_len =
                    table_entry->old_modEoCSoftwareUpgradeFileName_len;
                break;
            case COLUMN_MODEOCSOFTWAREUPGRADEPROCEED:
                table_entry->modEoCSoftwareUpgradeProceed =
                    table_entry->old_modEoCSoftwareUpgradeProceed;
                table_entry->old_modEoCSoftwareUpgradeProceed = 0;
                break;
            }
        }
        break;

    case MODE_SET_COMMIT:
        break;
    }
    return SNMP_ERR_NOERROR;
}
