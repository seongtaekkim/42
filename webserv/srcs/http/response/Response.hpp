#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include "HTTPState.hpp"
#include "../../util/Storage.hpp"
#include "StatusLine.hpp"
#include "ResponseByFile.hpp"

// #include "../Header.hpp"
// #include "make/ResponseMaker.hpp"

// class ResponseMaker;

class Response {
private:
	HTTPStatus::StateType	_status;
	// ResponseMaker			_maker;
	// Header _header;
	ResponseByFile*		_body;
	std::string _headString;
	
public:
	Response(void);
	Response(const Response& other);
	Response& operator=(const Response& other);
	~Response(void);
	bool store(Storage& buffer);
	ResponseByFile* body(void) const;
	void body(ResponseByFile* body);

	void status(HTTPStatus::StateType& status);
	HTTPStatus::StateType& status(void);
	enum State { INIT, HEADER, BODY, END };
	State _state;


};


#endif