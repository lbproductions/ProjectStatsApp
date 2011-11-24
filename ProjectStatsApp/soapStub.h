/* soapStub.h
   Generated by gSOAP 2.8.4 from servicedescription.h

Copyright(C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapStub_H
#define soapStub_H
#ifndef SERVICEDESCRIPTION_H
#define SERVICEDESCRIPTION_H
#include <vector>
#endif // SERVICEDESCRIPTION_H
#include "stdsoap2.h"

/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#if 0 /* volatile type: do not declare here, declared elsewhere */

#endif

#ifndef SOAP_TYPE_StringIntPair
#define SOAP_TYPE_StringIntPair (9)
/* StringIntPair */
class SOAP_CMAC StringIntPair
{
public:
	char *key;	/* optional element of type xsd:string */
	int value;	/* required element of type xsd:int */
public:
	virtual int soap_type() const { return 9; } /* = unique id SOAP_TYPE_StringIntPair */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         StringIntPair() { StringIntPair::soap_default(NULL); }
	virtual ~StringIntPair() { }
};
#endif

#ifndef SOAP_TYPE_StringDoublePair
#define SOAP_TYPE_StringDoublePair (10)
/* StringDoublePair */
class SOAP_CMAC StringDoublePair
{
public:
	char *key;	/* optional element of type xsd:string */
	double value;	/* required element of type xsd:double */
public:
	virtual int soap_type() const { return 10; } /* = unique id SOAP_TYPE_StringDoublePair */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         StringDoublePair() { StringDoublePair::soap_default(NULL); }
	virtual ~StringDoublePair() { }
};
#endif

#ifndef SOAP_TYPE_PlayerInformation
#define SOAP_TYPE_PlayerInformation (12)
/* PlayerInformation */
class SOAP_CMAC PlayerInformation
{
public:
	int id;	/* required element of type xsd:int */
	char *name;	/* optional element of type xsd:string */
	std::vector<StringIntPair >games;	/* optional element of type StringIntPair */
	std::vector<StringIntPair >wins;	/* optional element of type StringIntPair */
	std::vector<StringIntPair >losses;	/* optional element of type StringIntPair */
	std::vector<StringIntPair >points;	/* optional element of type StringIntPair */
	std::vector<StringDoublePair >average;	/* optional element of type StringDoublePair */
public:
	virtual int soap_type() const { return 12; } /* = unique id SOAP_TYPE_PlayerInformation */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         PlayerInformation() { PlayerInformation::soap_default(NULL); }
	virtual ~PlayerInformation() { }
};
#endif

#ifndef SOAP_TYPE_PlayerList
#define SOAP_TYPE_PlayerList (15)
/* PlayerList */
class SOAP_CMAC PlayerList
{
public:
	std::vector<PlayerInformation >playerList;	/* optional element of type PlayerInformation */
public:
	virtual int soap_type() const { return 15; } /* = unique id SOAP_TYPE_PlayerList */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         PlayerList() { PlayerList::soap_default(NULL); }
	virtual ~PlayerList() { }
};
#endif

#ifndef SOAP_TYPE_DrinkInformation
#define SOAP_TYPE_DrinkInformation (17)
/* DrinkInformation */
class SOAP_CMAC DrinkInformation
{
public:
	int id;	/* required element of type xsd:int */
	char *name;	/* optional element of type xsd:string */
	char *type;	/* optional element of type xsd:string */
	double size;	/* required element of type xsd:double */
	double alc;	/* required element of type xsd:double */
	int drinkCount;	/* required element of type xsd:int */
	std::vector<StringIntPair >drinksPerPlayer;	/* optional element of type StringIntPair */
public:
	virtual int soap_type() const { return 17; } /* = unique id SOAP_TYPE_DrinkInformation */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         DrinkInformation() { DrinkInformation::soap_default(NULL); }
	virtual ~DrinkInformation() { }
};
#endif

#ifndef SOAP_TYPE_DrinkList
#define SOAP_TYPE_DrinkList (18)
/* DrinkList */
class SOAP_CMAC DrinkList
{
public:
	std::vector<DrinkInformation >drinkList;	/* optional element of type DrinkInformation */
public:
	virtual int soap_type() const { return 18; } /* = unique id SOAP_TYPE_DrinkList */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         DrinkList() { DrinkList::soap_default(NULL); }
	virtual ~DrinkList() { }
};
#endif

#ifndef SOAP_TYPE_PlaceInformation
#define SOAP_TYPE_PlaceInformation (20)
/* PlaceInformation */
class SOAP_CMAC PlaceInformation
{
public:
	int id;	/* required element of type xsd:int */
	char *name;	/* optional element of type xsd:string */
	int plz;	/* required element of type xsd:int */
	char *ort;	/* optional element of type xsd:string */
	char *strasse;	/* optional element of type xsd:string */
	int number;	/* required element of type xsd:int */
	char *comment;	/* optional element of type xsd:string */
	int gameCount;	/* required element of type xsd:int */
	std::vector<char * >players;	/* optional element of type xsd:string */
public:
	virtual int soap_type() const { return 20; } /* = unique id SOAP_TYPE_PlaceInformation */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         PlaceInformation() { PlaceInformation::soap_default(NULL); }
	virtual ~PlaceInformation() { }
};
#endif

#ifndef SOAP_TYPE_PlaceList
#define SOAP_TYPE_PlaceList (22)
/* PlaceList */
class SOAP_CMAC PlaceList
{
public:
	std::vector<PlaceInformation >placeList;	/* optional element of type PlaceInformation */
public:
	virtual int soap_type() const { return 22; } /* = unique id SOAP_TYPE_PlaceList */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         PlaceList() { PlaceList::soap_default(NULL); }
	virtual ~PlaceList() { }
};
#endif

#ifndef SOAP_TYPE_GameInformation
#define SOAP_TYPE_GameInformation (24)
/* GameInformation */
class SOAP_CMAC GameInformation
{
public:
	int id;	/* required element of type xsd:int */
	char *name;	/* optional element of type xsd:string */
	char *date;	/* optional element of type xsd:string */
	bool isLive;	/* required element of type xsd:boolean */
	std::vector<PlayerInformation >playersSortedByPosition;	/* optional element of type PlayerInformation */
	std::vector<PlayerInformation >currentPlayingPlayers;	/* optional element of type PlayerInformation */
public:
	virtual int soap_type() const { return 24; } /* = unique id SOAP_TYPE_GameInformation */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         GameInformation() { GameInformation::soap_default(NULL); }
	virtual ~GameInformation() { }
};
#endif

#ifndef SOAP_TYPE_GameList
#define SOAP_TYPE_GameList (26)
/* GameList */
class SOAP_CMAC GameList
{
public:
	std::vector<GameInformation >gameList;	/* optional element of type GameInformation */
public:
	virtual int soap_type() const { return 26; } /* = unique id SOAP_TYPE_GameList */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         GameList() { GameList::soap_default(NULL); }
	virtual ~GameList() { }
};
#endif

#ifndef SOAP_TYPE_ps__playerByIdResponse
#define SOAP_TYPE_ps__playerByIdResponse (30)
/* ps:playerByIdResponse */
struct ps__playerByIdResponse
{
public:
	PlayerInformation result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type PlayerInformation */
};
#endif

#ifndef SOAP_TYPE_ps__playerById
#define SOAP_TYPE_ps__playerById (31)
/* ps:playerById */
struct ps__playerById
{
public:
	int id;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ps__playerListResponse
#define SOAP_TYPE_ps__playerListResponse (34)
/* ps:playerListResponse */
struct ps__playerListResponse
{
public:
	PlayerList result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type PlayerList */
};
#endif

#ifndef SOAP_TYPE_ps__playerList
#define SOAP_TYPE_ps__playerList (35)
/* ps:playerList */
struct ps__playerList
{
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#ifndef SOAP_TYPE_ps__drinkListResponse
#define SOAP_TYPE_ps__drinkListResponse (38)
/* ps:drinkListResponse */
struct ps__drinkListResponse
{
public:
	DrinkList result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type DrinkList */
};
#endif

#ifndef SOAP_TYPE_ps__drinkList
#define SOAP_TYPE_ps__drinkList (39)
/* ps:drinkList */
struct ps__drinkList
{
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#ifndef SOAP_TYPE_ps__placeListResponse
#define SOAP_TYPE_ps__placeListResponse (42)
/* ps:placeListResponse */
struct ps__placeListResponse
{
public:
	PlaceList result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type PlaceList */
};
#endif

#ifndef SOAP_TYPE_ps__placeList
#define SOAP_TYPE_ps__placeList (43)
/* ps:placeList */
struct ps__placeList
{
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#ifndef SOAP_TYPE_ps__gameListResponse
#define SOAP_TYPE_ps__gameListResponse (46)
/* ps:gameListResponse */
struct ps__gameListResponse
{
public:
	GameList result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type GameList */
};
#endif

#ifndef SOAP_TYPE_ps__gameList
#define SOAP_TYPE_ps__gameList (47)
/* ps:gameList */
struct ps__gameList
{
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#ifndef SOAP_TYPE_ps__gameCurrentPlayingPlayersResponse
#define SOAP_TYPE_ps__gameCurrentPlayingPlayersResponse (49)
/* ps:gameCurrentPlayingPlayersResponse */
struct ps__gameCurrentPlayingPlayersResponse
{
public:
	PlayerList result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type PlayerList */
};
#endif

#ifndef SOAP_TYPE_ps__gameCurrentPlayingPlayers
#define SOAP_TYPE_ps__gameCurrentPlayingPlayers (50)
/* ps:gameCurrentPlayingPlayers */
struct ps__gameCurrentPlayingPlayers
{
public:
	int gameId;	/* required element of type xsd:int */
};
#endif

#if 0 /* volatile type: do not declare here, declared elsewhere */

#endif

#ifndef SOAP_TYPE_ps__addSchmeissereiResponse
#define SOAP_TYPE_ps__addSchmeissereiResponse (54)
/* ps:addSchmeissereiResponse */
struct ps__addSchmeissereiResponse
{
public:
	std::string result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ps__addSchmeisserei
#define SOAP_TYPE_ps__addSchmeisserei (55)
/* ps:addSchmeisserei */
struct ps__addSchmeisserei
{
public:
	int gameId;	/* required element of type xsd:int */
	int playerId;	/* required element of type xsd:int */
	std::string type;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ps__addDrinkResponse
#define SOAP_TYPE_ps__addDrinkResponse (57)
/* ps:addDrinkResponse */
struct ps__addDrinkResponse
{
public:
	std::string result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ps__addDrink
#define SOAP_TYPE_ps__addDrink (58)
/* ps:addDrink */
struct ps__addDrink
{
public:
	int gameId;	/* required element of type xsd:int */
	int playerId;	/* required element of type xsd:int */
	int drinkId;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ps__addRoundResponse
#define SOAP_TYPE_ps__addRoundResponse (60)
/* ps:addRoundResponse */
struct ps__addRoundResponse
{
public:
	std::string result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ps__addRound
#define SOAP_TYPE_ps__addRound (61)
/* ps:addRound */
struct ps__addRound
{
public:
	int gameId;	/* required element of type xsd:int */
	int re1PlayerId;	/* required element of type xsd:int */
	int re2PlayerId;	/* required element of type xsd:int */
	int hochzeitPlayerId;	/* required element of type xsd:int */
	int schweinereiPlayerId;	/* required element of type xsd:int */
	int trumpfabgabePlayerId;	/* required element of type xsd:int */
	std::string soloType;	/* required element of type xsd:string */
	bool pflichtsolo;	/* required element of type xsd:boolean */
	int points;	/* required element of type xsd:int */
	std::string comment;	/* required element of type xsd:string */
};
#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (62)
/* SOAP Header: */
struct SOAP_ENV__Header
{
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (63)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (65)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
public:
	char *__any;
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (68)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (69)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
public:
	char *faultcode;	/* optional element of type xsd:QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
};
#endif

#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
typedef char *_XML;
#endif

#ifndef SOAP_TYPE_xsd__string
#define SOAP_TYPE_xsd__string (8)
typedef char *xsd__string;
#endif


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


#endif

/* End of soapStub.h */
