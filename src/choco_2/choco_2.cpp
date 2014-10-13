// choco_2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#include <map>

#include "choco/choco.h"
#include "card_server/server.h"

#pragma comment (lib,"ws2_32")
#pragma comment (lib,"MSWSock")
#pragma comment (lib,"libcurl")
#pragma comment (lib,"libmysql")

using namespace std;

choco::server::server *sv;

int _tmain(int argc, _TCHAR* argv[]){

	map<string,string> dst;
	choco::config::from_file("config.cgf");
	choco::config::print();

	/*
		orm config�� ������ ����� �����°Ŷ�
		���� config�� ���� ���� �ȵ�.
	*/
	choco::orm::configure("user", "root");
	choco::orm::configure("password", "asdf1234");
	choco::orm::configure("db", "test");

	choco::initialize(
		choco::init_log | choco::init_parallel |
		choco::init_mysql);

	card_server *intf = new card_server();
	choco::server::server *server = new
		choco::server::server(intf);

	sv = server;
	
	if(server->open()){
		choco::log::error(
			"failed to open server\n");
		return 0;
	}


	while( true ){
		choco::log::output(
			"[running] / \n");
		Sleep(2000);
	};

	return 0;
}

