/* soapprojectstatsProxy.cpp
   Generated by gSOAP 2.8.4 from servicedescription.h

Copyright(C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#include "soapprojectstatsProxy.h"

projectstatsProxy::projectstatsProxy()
{	projectstatsProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

projectstatsProxy::projectstatsProxy(const struct soap &_soap) : soap(_soap)
{ }

projectstatsProxy::projectstatsProxy(const char *url)
{	projectstatsProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = url;
}

projectstatsProxy::projectstatsProxy(soap_mode iomode)
{	projectstatsProxy_init(iomode, iomode);
}

projectstatsProxy::projectstatsProxy(const char *url, soap_mode iomode)
{	projectstatsProxy_init(iomode, iomode);
	soap_endpoint = url;
}

projectstatsProxy::projectstatsProxy(soap_mode imode, soap_mode omode)
{	projectstatsProxy_init(imode, omode);
}

projectstatsProxy::~projectstatsProxy()
{ }

void projectstatsProxy::projectstatsProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ps", "urn:projectstats", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_set_namespaces(this, namespaces);
}

void projectstatsProxy::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void projectstatsProxy::soap_noheader()
{	this->header = NULL;
}

const SOAP_ENV__Header *projectstatsProxy::soap_header()
{	return this->header;
}

const SOAP_ENV__Fault *projectstatsProxy::soap_fault()
{	return this->fault;
}

const char *projectstatsProxy::soap_fault_string()
{	return *soap_faultstring(this);
}

const char *projectstatsProxy::soap_fault_detail()
{	return *soap_faultdetail(this);
}

int projectstatsProxy::soap_close_socket()
{	return soap_closesock(this);
}

int projectstatsProxy::soap_force_close_socket()
{	return soap_force_closesock(this);
}

void projectstatsProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
void projectstatsProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}

char *projectstatsProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int projectstatsProxy::playerById(const char *endpoint, const char *soap_action, int id, PlayerInformation &result)
{	struct soap *soap = this;
	struct ps__playerById soap_tmp_ps__playerById;
	struct ps__playerByIdResponse *soap_tmp_ps__playerByIdResponse;
	if (endpoint)
		soap_endpoint = endpoint;
	if (!soap_endpoint)
		soap_endpoint = "http://eineurl.von.uns? http://eineurl.von.uns? http://eineurl.von.uns? http://eineurl.von.uns?";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp_ps__playerById.id = id;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ps__playerById(soap, &soap_tmp_ps__playerById);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ps__playerById(soap, &soap_tmp_ps__playerById, "ps:playerById", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ps__playerById(soap, &soap_tmp_ps__playerById, "ps:playerById", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&result)
		return soap_closesock(soap);
	result.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ps__playerByIdResponse = soap_get_ps__playerByIdResponse(soap, NULL, "ps:playerByIdResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_ps__playerByIdResponse->result;
	return soap_closesock(soap);
}

int projectstatsProxy::playerList(const char *endpoint, const char *soap_action, PlayerList &result)
{	struct soap *soap = this;
	struct ps__playerList soap_tmp_ps__playerList;
	struct ps__playerListResponse *soap_tmp_ps__playerListResponse;
	if (endpoint)
		soap_endpoint = endpoint;
	if (!soap_endpoint)
		soap_endpoint = "http://eineurl.von.uns? http://eineurl.von.uns? http://eineurl.von.uns? http://eineurl.von.uns?";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ps__playerList(soap, &soap_tmp_ps__playerList);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ps__playerList(soap, &soap_tmp_ps__playerList, "ps:playerList", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ps__playerList(soap, &soap_tmp_ps__playerList, "ps:playerList", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&result)
		return soap_closesock(soap);
	result.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ps__playerListResponse = soap_get_ps__playerListResponse(soap, NULL, "ps:playerListResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_ps__playerListResponse->result;
	return soap_closesock(soap);
}

int projectstatsProxy::drinkList(const char *endpoint, const char *soap_action, DrinkList &result)
{	struct soap *soap = this;
	struct ps__drinkList soap_tmp_ps__drinkList;
	struct ps__drinkListResponse *soap_tmp_ps__drinkListResponse;
	if (endpoint)
		soap_endpoint = endpoint;
	if (!soap_endpoint)
		soap_endpoint = "http://eineurl.von.uns? http://eineurl.von.uns? http://eineurl.von.uns? http://eineurl.von.uns?";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ps__drinkList(soap, &soap_tmp_ps__drinkList);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ps__drinkList(soap, &soap_tmp_ps__drinkList, "ps:drinkList", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ps__drinkList(soap, &soap_tmp_ps__drinkList, "ps:drinkList", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&result)
		return soap_closesock(soap);
	result.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ps__drinkListResponse = soap_get_ps__drinkListResponse(soap, NULL, "ps:drinkListResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_ps__drinkListResponse->result;
	return soap_closesock(soap);
}

int projectstatsProxy::placeList(const char *endpoint, const char *soap_action, PlaceList &result)
{	struct soap *soap = this;
	struct ps__placeList soap_tmp_ps__placeList;
	struct ps__placeListResponse *soap_tmp_ps__placeListResponse;
	if (endpoint)
		soap_endpoint = endpoint;
	if (!soap_endpoint)
		soap_endpoint = "http://eineurl.von.uns? http://eineurl.von.uns? http://eineurl.von.uns? http://eineurl.von.uns?";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ps__placeList(soap, &soap_tmp_ps__placeList);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ps__placeList(soap, &soap_tmp_ps__placeList, "ps:placeList", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ps__placeList(soap, &soap_tmp_ps__placeList, "ps:placeList", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&result)
		return soap_closesock(soap);
	result.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ps__placeListResponse = soap_get_ps__placeListResponse(soap, NULL, "ps:placeListResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_ps__placeListResponse->result;
	return soap_closesock(soap);
}
/* End of client proxy code */
