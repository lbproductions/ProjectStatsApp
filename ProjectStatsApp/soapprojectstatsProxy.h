/* soapprojectstatsProxy.h
   Generated by gSOAP 2.8.4 from servicedescription.h

Copyright(C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapprojectstatsProxy_H
#define soapprojectstatsProxy_H
#include "soapH.h"

class SOAP_CMAC projectstatsProxy : public soap
{ public:
	/// Endpoint URL of service 'projectstatsProxy' (change as needed)
	const char *soap_endpoint;
	/// Constructor
	projectstatsProxy();
	/// Constructor with copy of another engine state
	projectstatsProxy(const struct soap&);
	/// Constructor with endpoint URL
	projectstatsProxy(const char *url);
	/// Constructor with engine input+output mode control
	projectstatsProxy(soap_mode iomode);
	/// Constructor with URL and input+output mode control
	projectstatsProxy(const char *url, soap_mode iomode);
	/// Constructor with engine input and output mode control
	projectstatsProxy(soap_mode imode, soap_mode omode);
	/// Destructor frees deserialized data
	virtual	~projectstatsProxy();
	/// Initializer used by constructors
	virtual	void projectstatsProxy_init(soap_mode imode, soap_mode omode);
	/// Delete all deserialized data (uses soap_destroy and soap_end)
	virtual	void destroy();
	/// Disables and removes SOAP Header from message
	virtual	void soap_noheader();
	/// Get SOAP Header structure (NULL when absent)
	virtual	const SOAP_ENV__Header *soap_header();
	/// Get SOAP Fault structure (NULL when absent)
	virtual	const SOAP_ENV__Fault *soap_fault();
	/// Get SOAP Fault string (NULL when absent)
	virtual	const char *soap_fault_string();
	/// Get SOAP Fault detail as string (NULL when absent)
	virtual	const char *soap_fault_detail();
	/// Close connection (normally automatic, except for send_X ops)
	virtual	int soap_close_socket();
	/// Force close connection (can kill a thread blocked on IO)
	virtual	int soap_force_close_socket();
	/// Print fault
	virtual	void soap_print_fault(FILE*);
#ifndef WITH_LEAN
	/// Print fault to stream
	virtual	void soap_stream_fault(std::ostream&);
	/// Put fault into buffer
	virtual	char *soap_sprint_fault(char *buf, size_t len);
#endif

	/// Web service operation 'playerById' (returns error code or SOAP_OK)
	virtual	int playerById(int id, PlayerInformation &result) { return playerById(NULL, NULL, id, result); }
	virtual	int playerById(const char *endpoint, const char *soap_action, int id, PlayerInformation &result);

	/// Web service operation 'playerList' (returns error code or SOAP_OK)
	virtual	int playerList(PlayerList &result) { return playerList(NULL, NULL, result); }
	virtual	int playerList(const char *endpoint, const char *soap_action, PlayerList &result);

	/// Web service operation 'drinkList' (returns error code or SOAP_OK)
	virtual	int drinkList(DrinkList &result) { return drinkList(NULL, NULL, result); }
	virtual	int drinkList(const char *endpoint, const char *soap_action, DrinkList &result);

	/// Web service operation 'placeList' (returns error code or SOAP_OK)
	virtual	int placeList(PlaceList &result) { return placeList(NULL, NULL, result); }
	virtual	int placeList(const char *endpoint, const char *soap_action, PlaceList &result);

	/// Web service operation 'gameList' (returns error code or SOAP_OK)
	virtual	int gameList(GameList &result) { return gameList(NULL, NULL, result); }
	virtual	int gameList(const char *endpoint, const char *soap_action, GameList &result);

	/// Web service operation 'gameCurrentPlayingPlayers' (returns error code or SOAP_OK)
	virtual	int gameCurrentPlayingPlayers(int gameId, PlayerList &result) { return gameCurrentPlayingPlayers(NULL, NULL, gameId, result); }
	virtual	int gameCurrentPlayingPlayers(const char *endpoint, const char *soap_action, int gameId, PlayerList &result);

	/// Web service operation 'addSchmeisserei' (returns error code or SOAP_OK)
	virtual	int addSchmeisserei(int gameId, int playerId, std::string type, std::string &result) { return addSchmeisserei(NULL, NULL, gameId, playerId, type, result); }
	virtual	int addSchmeisserei(const char *endpoint, const char *soap_action, int gameId, int playerId, std::string type, std::string &result);

	/// Web service operation 'addDrink' (returns error code or SOAP_OK)
	virtual	int addDrink(int gameId, int playerId, int drinkId, std::string &result) { return addDrink(NULL, NULL, gameId, playerId, drinkId, result); }
	virtual	int addDrink(const char *endpoint, const char *soap_action, int gameId, int playerId, int drinkId, std::string &result);

	/// Web service operation 'addRound' (returns error code or SOAP_OK)
	virtual	int addRound(int gameId, int re1PlayerId, int re2PlayerId, int hochzeitPlayerId, int schweinereiPlayerId, int trumpfabgabePlayerId, std::string soloType, bool pflichtsolo, int points, std::string comment, std::string &result) { return addRound(NULL, NULL, gameId, re1PlayerId, re2PlayerId, hochzeitPlayerId, schweinereiPlayerId, trumpfabgabePlayerId, soloType, pflichtsolo, points, comment, result); }
	virtual	int addRound(const char *endpoint, const char *soap_action, int gameId, int re1PlayerId, int re2PlayerId, int hochzeitPlayerId, int schweinereiPlayerId, int trumpfabgabePlayerId, std::string soloType, bool pflichtsolo, int points, std::string comment, std::string &result);
};
#endif
