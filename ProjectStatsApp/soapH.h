/* soapH.h
   Generated by gSOAP 2.8.4 from servicedescription.h

Copyright(C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapH_H
#define soapH_H
#include "soapStub.h"
#ifndef WITH_NOIDREF

#ifdef __cplusplus
extern "C" {
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_markelement(struct soap*, const void*, int);
SOAP_FMAC3 int SOAP_FMAC4 soap_putelement(struct soap*, const void*, const char*, int, int);
SOAP_FMAC3 void *SOAP_FMAC4 soap_getelement(struct soap*, int*);

#ifdef __cplusplus
}
#endif
SOAP_FMAC3 int SOAP_FMAC4 soap_putindependent(struct soap*);
SOAP_FMAC3 int SOAP_FMAC4 soap_getindependent(struct soap*);
#endif
SOAP_FMAC3 int SOAP_FMAC4 soap_ignore_element(struct soap*);

SOAP_FMAC3 void * SOAP_FMAC4 soap_instantiate(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 int SOAP_FMAC4 soap_fdelete(struct soap_clist*);
SOAP_FMAC3 void* SOAP_FMAC4 soap_class_id_enter(struct soap*, const char*, void*, int, size_t, const char*, const char*);

SOAP_FMAC3 void* SOAP_FMAC4 soap_container_id_forward(struct soap*, const char*, void*, size_t, int, int, size_t, unsigned int);

SOAP_FMAC3 void SOAP_FMAC4 soap_container_insert(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_byte
#define SOAP_TYPE_byte (3)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_byte(struct soap*, char *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_byte(struct soap*, const char*, int, const char *, const char*);
SOAP_FMAC3 char * SOAP_FMAC4 soap_in_byte(struct soap*, const char*, char *, const char*);

#ifndef soap_write_byte
#define soap_write_byte(soap, data) ( soap_begin_send(soap) || soap_put_byte(soap, data, "byte", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_byte(struct soap*, const char *, const char*, const char*);

#ifndef soap_read_byte
#define soap_read_byte(soap, data) ( soap_begin_recv(soap) || !soap_get_byte(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 char * SOAP_FMAC4 soap_get_byte(struct soap*, char *, const char*, const char*);

#ifndef SOAP_TYPE_int
#define SOAP_TYPE_int (1)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_int(struct soap*, int *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_int(struct soap*, const char*, int, const int *, const char*);
SOAP_FMAC3 int * SOAP_FMAC4 soap_in_int(struct soap*, const char*, int *, const char*);

#ifndef soap_write_int
#define soap_write_int(soap, data) ( soap_begin_send(soap) || soap_put_int(soap, data, "int", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_int(struct soap*, const int *, const char*, const char*);

#ifndef soap_read_int
#define soap_read_int(soap, data) ( soap_begin_recv(soap) || !soap_get_int(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 int * SOAP_FMAC4 soap_get_int(struct soap*, int *, const char*, const char*);

#ifndef SOAP_TYPE_PlayerList
#define SOAP_TYPE_PlayerList (10)
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_out_PlayerList(struct soap*, const char*, int, const PlayerList *, const char*);
SOAP_FMAC3 PlayerList * SOAP_FMAC4 soap_in_PlayerList(struct soap*, const char*, PlayerList *, const char*);

#ifndef soap_write_PlayerList
#define soap_write_PlayerList(soap, data) ( soap_begin_send(soap) || ((data)->soap_serialize(soap), 0) || (data)->soap_put(soap, "PlayerList", NULL) || soap_end_send(soap) )
#endif


#ifndef soap_read_PlayerList
#define soap_read_PlayerList(soap, data) ( soap_begin_recv(soap) || !soap_get_PlayerList(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 PlayerList * SOAP_FMAC4 soap_get_PlayerList(struct soap*, PlayerList *, const char*, const char*);

#define soap_new_PlayerList(soap, n) soap_instantiate_PlayerList(soap, n, NULL, NULL, NULL)


#define soap_delete_PlayerList(soap, p) soap_delete(soap, p)

SOAP_FMAC1 PlayerList * SOAP_FMAC2 soap_instantiate_PlayerList(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_PlayerList(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_PlayerInformation
#define SOAP_TYPE_PlayerInformation (9)
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_out_PlayerInformation(struct soap*, const char*, int, const PlayerInformation *, const char*);
SOAP_FMAC3 PlayerInformation * SOAP_FMAC4 soap_in_PlayerInformation(struct soap*, const char*, PlayerInformation *, const char*);

#ifndef soap_write_PlayerInformation
#define soap_write_PlayerInformation(soap, data) ( soap_begin_send(soap) || ((data)->soap_serialize(soap), 0) || (data)->soap_put(soap, "PlayerInformation", NULL) || soap_end_send(soap) )
#endif


#ifndef soap_read_PlayerInformation
#define soap_read_PlayerInformation(soap, data) ( soap_begin_recv(soap) || !soap_get_PlayerInformation(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 PlayerInformation * SOAP_FMAC4 soap_get_PlayerInformation(struct soap*, PlayerInformation *, const char*, const char*);

#define soap_new_PlayerInformation(soap, n) soap_instantiate_PlayerInformation(soap, n, NULL, NULL, NULL)


#define soap_delete_PlayerInformation(soap, p) soap_delete(soap, p)

SOAP_FMAC1 PlayerInformation * SOAP_FMAC2 soap_instantiate_PlayerInformation(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_PlayerInformation(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (27)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Fault(struct soap*, const struct SOAP_ENV__Fault *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Fault(struct soap*, const char*, int, const struct SOAP_ENV__Fault *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_in_SOAP_ENV__Fault(struct soap*, const char*, struct SOAP_ENV__Fault *, const char*);

#ifndef soap_write_SOAP_ENV__Fault
#define soap_write_SOAP_ENV__Fault(soap, data) ( soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Fault(soap, data), 0) || soap_put_SOAP_ENV__Fault(soap, data, "SOAP-ENV:Fault", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Fault(struct soap*, const struct SOAP_ENV__Fault *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Fault
#define soap_read_SOAP_ENV__Fault(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Fault(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_get_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault *, const char*, const char*);

#define soap_new_SOAP_ENV__Fault(soap, n) soap_instantiate_SOAP_ENV__Fault(soap, n, NULL, NULL, NULL)


#define soap_delete_SOAP_ENV__Fault(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct SOAP_ENV__Fault * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Fault(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Fault(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (26)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Reason(struct soap*, const struct SOAP_ENV__Reason *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Reason(struct soap*, const char*, int, const struct SOAP_ENV__Reason *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_in_SOAP_ENV__Reason(struct soap*, const char*, struct SOAP_ENV__Reason *, const char*);

#ifndef soap_write_SOAP_ENV__Reason
#define soap_write_SOAP_ENV__Reason(soap, data) ( soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Reason(soap, data), 0) || soap_put_SOAP_ENV__Reason(soap, data, "SOAP-ENV:Reason", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Reason(struct soap*, const struct SOAP_ENV__Reason *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Reason
#define soap_read_SOAP_ENV__Reason(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Reason(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_get_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *, const char*, const char*);

#define soap_new_SOAP_ENV__Reason(soap, n) soap_instantiate_SOAP_ENV__Reason(soap, n, NULL, NULL, NULL)


#define soap_delete_SOAP_ENV__Reason(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct SOAP_ENV__Reason * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Reason(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Reason(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (23)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Detail(struct soap*, const struct SOAP_ENV__Detail *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Detail(struct soap*, const char*, int, const struct SOAP_ENV__Detail *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_in_SOAP_ENV__Detail(struct soap*, const char*, struct SOAP_ENV__Detail *, const char*);

#ifndef soap_write_SOAP_ENV__Detail
#define soap_write_SOAP_ENV__Detail(soap, data) ( soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Detail(soap, data), 0) || soap_put_SOAP_ENV__Detail(soap, data, "SOAP-ENV:Detail", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Detail(struct soap*, const struct SOAP_ENV__Detail *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Detail
#define soap_read_SOAP_ENV__Detail(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Detail(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_get_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *, const char*, const char*);

#define soap_new_SOAP_ENV__Detail(soap, n) soap_instantiate_SOAP_ENV__Detail(soap, n, NULL, NULL, NULL)


#define soap_delete_SOAP_ENV__Detail(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct SOAP_ENV__Detail * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Detail(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Detail(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (21)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Code(struct soap*, const struct SOAP_ENV__Code *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Code(struct soap*, const char*, int, const struct SOAP_ENV__Code *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_in_SOAP_ENV__Code(struct soap*, const char*, struct SOAP_ENV__Code *, const char*);

#ifndef soap_write_SOAP_ENV__Code
#define soap_write_SOAP_ENV__Code(soap, data) ( soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Code(soap, data), 0) || soap_put_SOAP_ENV__Code(soap, data, "SOAP-ENV:Code", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Code(struct soap*, const struct SOAP_ENV__Code *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Code
#define soap_read_SOAP_ENV__Code(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Code(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_get_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *, const char*, const char*);

#define soap_new_SOAP_ENV__Code(soap, n) soap_instantiate_SOAP_ENV__Code(soap, n, NULL, NULL, NULL)


#define soap_delete_SOAP_ENV__Code(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct SOAP_ENV__Code * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Code(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Code(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (20)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Header(struct soap*, const struct SOAP_ENV__Header *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Header(struct soap*, const char*, int, const struct SOAP_ENV__Header *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_in_SOAP_ENV__Header(struct soap*, const char*, struct SOAP_ENV__Header *, const char*);

#ifndef soap_write_SOAP_ENV__Header
#define soap_write_SOAP_ENV__Header(soap, data) ( soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Header(soap, data), 0) || soap_put_SOAP_ENV__Header(soap, data, "SOAP-ENV:Header", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Header(struct soap*, const struct SOAP_ENV__Header *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Header
#define soap_read_SOAP_ENV__Header(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Header(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_get_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header *, const char*, const char*);

#define soap_new_SOAP_ENV__Header(soap, n) soap_instantiate_SOAP_ENV__Header(soap, n, NULL, NULL, NULL)


#define soap_delete_SOAP_ENV__Header(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct SOAP_ENV__Header * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Header(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Header(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef SOAP_TYPE_ps__playerList
#define SOAP_TYPE_ps__playerList (19)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ps__playerList(struct soap*, struct ps__playerList *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ps__playerList(struct soap*, const struct ps__playerList *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ps__playerList(struct soap*, const char*, int, const struct ps__playerList *, const char*);
SOAP_FMAC3 struct ps__playerList * SOAP_FMAC4 soap_in_ps__playerList(struct soap*, const char*, struct ps__playerList *, const char*);

#ifndef soap_write_ps__playerList
#define soap_write_ps__playerList(soap, data) ( soap_begin_send(soap) || (soap_serialize_ps__playerList(soap, data), 0) || soap_put_ps__playerList(soap, data, "ps:playerList", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_ps__playerList(struct soap*, const struct ps__playerList *, const char*, const char*);

#ifndef soap_read_ps__playerList
#define soap_read_ps__playerList(soap, data) ( soap_begin_recv(soap) || !soap_get_ps__playerList(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct ps__playerList * SOAP_FMAC4 soap_get_ps__playerList(struct soap*, struct ps__playerList *, const char*, const char*);

#define soap_new_ps__playerList(soap, n) soap_instantiate_ps__playerList(soap, n, NULL, NULL, NULL)


#define soap_delete_ps__playerList(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct ps__playerList * SOAP_FMAC2 soap_instantiate_ps__playerList(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ps__playerList(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ps__playerListResponse
#define SOAP_TYPE_ps__playerListResponse (18)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ps__playerListResponse(struct soap*, struct ps__playerListResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ps__playerListResponse(struct soap*, const struct ps__playerListResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ps__playerListResponse(struct soap*, const char*, int, const struct ps__playerListResponse *, const char*);
SOAP_FMAC3 struct ps__playerListResponse * SOAP_FMAC4 soap_in_ps__playerListResponse(struct soap*, const char*, struct ps__playerListResponse *, const char*);

#ifndef soap_write_ps__playerListResponse
#define soap_write_ps__playerListResponse(soap, data) ( soap_begin_send(soap) || (soap_serialize_ps__playerListResponse(soap, data), 0) || soap_put_ps__playerListResponse(soap, data, "ps:playerListResponse", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_ps__playerListResponse(struct soap*, const struct ps__playerListResponse *, const char*, const char*);

#ifndef soap_read_ps__playerListResponse
#define soap_read_ps__playerListResponse(soap, data) ( soap_begin_recv(soap) || !soap_get_ps__playerListResponse(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct ps__playerListResponse * SOAP_FMAC4 soap_get_ps__playerListResponse(struct soap*, struct ps__playerListResponse *, const char*, const char*);

#define soap_new_ps__playerListResponse(soap, n) soap_instantiate_ps__playerListResponse(soap, n, NULL, NULL, NULL)


#define soap_delete_ps__playerListResponse(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct ps__playerListResponse * SOAP_FMAC2 soap_instantiate_ps__playerListResponse(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ps__playerListResponse(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ps__playerById
#define SOAP_TYPE_ps__playerById (15)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ps__playerById(struct soap*, struct ps__playerById *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ps__playerById(struct soap*, const struct ps__playerById *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ps__playerById(struct soap*, const char*, int, const struct ps__playerById *, const char*);
SOAP_FMAC3 struct ps__playerById * SOAP_FMAC4 soap_in_ps__playerById(struct soap*, const char*, struct ps__playerById *, const char*);

#ifndef soap_write_ps__playerById
#define soap_write_ps__playerById(soap, data) ( soap_begin_send(soap) || (soap_serialize_ps__playerById(soap, data), 0) || soap_put_ps__playerById(soap, data, "ps:playerById", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_ps__playerById(struct soap*, const struct ps__playerById *, const char*, const char*);

#ifndef soap_read_ps__playerById
#define soap_read_ps__playerById(soap, data) ( soap_begin_recv(soap) || !soap_get_ps__playerById(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct ps__playerById * SOAP_FMAC4 soap_get_ps__playerById(struct soap*, struct ps__playerById *, const char*, const char*);

#define soap_new_ps__playerById(soap, n) soap_instantiate_ps__playerById(soap, n, NULL, NULL, NULL)


#define soap_delete_ps__playerById(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct ps__playerById * SOAP_FMAC2 soap_instantiate_ps__playerById(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ps__playerById(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ps__playerByIdResponse
#define SOAP_TYPE_ps__playerByIdResponse (14)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ps__playerByIdResponse(struct soap*, struct ps__playerByIdResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ps__playerByIdResponse(struct soap*, const struct ps__playerByIdResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ps__playerByIdResponse(struct soap*, const char*, int, const struct ps__playerByIdResponse *, const char*);
SOAP_FMAC3 struct ps__playerByIdResponse * SOAP_FMAC4 soap_in_ps__playerByIdResponse(struct soap*, const char*, struct ps__playerByIdResponse *, const char*);

#ifndef soap_write_ps__playerByIdResponse
#define soap_write_ps__playerByIdResponse(soap, data) ( soap_begin_send(soap) || (soap_serialize_ps__playerByIdResponse(soap, data), 0) || soap_put_ps__playerByIdResponse(soap, data, "ps:playerByIdResponse", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_ps__playerByIdResponse(struct soap*, const struct ps__playerByIdResponse *, const char*, const char*);

#ifndef soap_read_ps__playerByIdResponse
#define soap_read_ps__playerByIdResponse(soap, data) ( soap_begin_recv(soap) || !soap_get_ps__playerByIdResponse(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct ps__playerByIdResponse * SOAP_FMAC4 soap_get_ps__playerByIdResponse(struct soap*, struct ps__playerByIdResponse *, const char*, const char*);

#define soap_new_ps__playerByIdResponse(soap, n) soap_instantiate_ps__playerByIdResponse(soap, n, NULL, NULL, NULL)


#define soap_delete_ps__playerByIdResponse(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct ps__playerByIdResponse * SOAP_FMAC2 soap_instantiate_ps__playerByIdResponse(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ps__playerByIdResponse(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Reason
#define SOAP_TYPE_PointerToSOAP_ENV__Reason (29)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Reason(struct soap*, const char *, int, struct SOAP_ENV__Reason *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Reason ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Reason(struct soap*, const char*, struct SOAP_ENV__Reason **, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Reason
#define soap_write_PointerToSOAP_ENV__Reason(soap, data) ( soap_begin_send(soap) || (soap_serialize_PointerToSOAP_ENV__Reason(soap, data), 0) || soap_put_PointerToSOAP_ENV__Reason(soap, data, "SOAP-ENV:Reason", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *const*, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Reason
#define soap_read_PointerToSOAP_ENV__Reason(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerToSOAP_ENV__Reason(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Reason ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason **, const char*, const char*);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Detail
#define SOAP_TYPE_PointerToSOAP_ENV__Detail (28)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Detail(struct soap*, const char *, int, struct SOAP_ENV__Detail *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Detail ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Detail(struct soap*, const char*, struct SOAP_ENV__Detail **, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Detail
#define soap_write_PointerToSOAP_ENV__Detail(soap, data) ( soap_begin_send(soap) || (soap_serialize_PointerToSOAP_ENV__Detail(soap, data), 0) || soap_put_PointerToSOAP_ENV__Detail(soap, data, "SOAP-ENV:Detail", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *const*, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Detail
#define soap_read_PointerToSOAP_ENV__Detail(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerToSOAP_ENV__Detail(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Detail ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail **, const char*, const char*);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Code
#define SOAP_TYPE_PointerToSOAP_ENV__Code (22)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Code(struct soap*, const char *, int, struct SOAP_ENV__Code *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Code ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Code(struct soap*, const char*, struct SOAP_ENV__Code **, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Code
#define soap_write_PointerToSOAP_ENV__Code(soap, data) ( soap_begin_send(soap) || (soap_serialize_PointerToSOAP_ENV__Code(soap, data), 0) || soap_put_PointerToSOAP_ENV__Code(soap, data, "SOAP-ENV:Code", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *const*, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Code
#define soap_read_PointerToSOAP_ENV__Code(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerToSOAP_ENV__Code(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Code ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code **, const char*, const char*);

#endif

#ifndef SOAP_TYPE_xsd__string
#define SOAP_TYPE_xsd__string (8)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_xsd__string(struct soap*, char **);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_xsd__string(struct soap*, char *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_xsd__string(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in_xsd__string(struct soap*, const char*, char **, const char*);

#ifndef soap_write_xsd__string
#define soap_write_xsd__string(soap, data) ( soap_begin_send(soap) || (soap_serialize_xsd__string(soap, data), 0) || soap_put_xsd__string(soap, data, "byte", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put_xsd__string(struct soap*, char *const*, const char*, const char*);

#ifndef soap_read_xsd__string
#define soap_read_xsd__string(soap, data) ( soap_begin_recv(soap) || !soap_get_xsd__string(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 char ** SOAP_FMAC4 soap_get_xsd__string(struct soap*, char **, const char*, const char*);

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default__QName(struct soap*, char **);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize__QName(struct soap*, char *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out__QName(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in__QName(struct soap*, const char*, char **, const char*);

#ifndef soap_write__QName
#define soap_write__QName(soap, data) ( soap_begin_send(soap) || (soap_serialize__QName(soap, data), 0) || soap_put__QName(soap, data, "byte", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put__QName(struct soap*, char *const*, const char*, const char*);

#ifndef soap_read__QName
#define soap_read__QName(soap, data) ( soap_begin_recv(soap) || !soap_get__QName(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 char ** SOAP_FMAC4 soap_get__QName(struct soap*, char **, const char*, const char*);

#ifndef SOAP_TYPE_string
#define SOAP_TYPE_string (4)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_string(struct soap*, char **);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_string(struct soap*, char *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_string(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in_string(struct soap*, const char*, char **, const char*);

#ifndef soap_write_string
#define soap_write_string(soap, data) ( soap_begin_send(soap) || (soap_serialize_string(soap, data), 0) || soap_put_string(soap, data, "byte", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put_string(struct soap*, char *const*, const char*, const char*);

#ifndef soap_read_string
#define soap_read_string(soap, data) ( soap_begin_recv(soap) || !soap_get_string(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 char ** SOAP_FMAC4 soap_get_string(struct soap*, char **, const char*, const char*);

#ifndef SOAP_TYPE_std__vectorTemplateOfPlayerInformation
#define SOAP_TYPE_std__vectorTemplateOfPlayerInformation (11)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_std__vectorTemplateOfPlayerInformation(struct soap*, std::vector<PlayerInformation >*);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_std__vectorTemplateOfPlayerInformation(struct soap*, const std::vector<PlayerInformation >*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_std__vectorTemplateOfPlayerInformation(struct soap*, const char*, int, const std::vector<PlayerInformation >*, const char*);
SOAP_FMAC3 std::vector<PlayerInformation >* SOAP_FMAC4 soap_in_std__vectorTemplateOfPlayerInformation(struct soap*, const char*, std::vector<PlayerInformation >*, const char*);

#define soap_new_std__vectorTemplateOfPlayerInformation(soap, n) soap_instantiate_std__vectorTemplateOfPlayerInformation(soap, n, NULL, NULL, NULL)


#define soap_delete_std__vectorTemplateOfPlayerInformation(soap, p) soap_delete(soap, p)

SOAP_FMAC1 std::vector<PlayerInformation > * SOAP_FMAC2 soap_instantiate_std__vectorTemplateOfPlayerInformation(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_std__vectorTemplateOfPlayerInformation(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

/* End of soapH.h */
