#include "orm.h"

#include "choco/log/log.h"

using namespace std;

namespace choco{
namespace orm{

	map<string,string> configs;

	void configure(
		const string &key, const string &value){

		configs[key] = value;
	}
	void configure_with_no_override(
		const string &key, const string &value){

		auto pair = configs.find( key );
		if( pair == configs.end() )
			configs[key] = value;
	}
	string &get_config(
		const string &key){

		return configs[key];
	}

	int initialize_config(){
		configure_with_no_override("host", "127.0.0.1");
		configure_with_no_override("port", "3306");
		configure_with_no_override("pool_size", "10");
		configure_with_no_override("log_query", "false");

		log::system(
			"orm::config - initialized\n");

		return 0;
	}

};};
