#include <SFML/Graphics/Text.hpp>
#include "../common/common_includes.h"

class Text{
public:
	struct{
		int x;
		int y;
		int currLine;
	}pos;
	sf::Text text;
	sf::Font font;//define input buffer
	std::string inputBuff;
	Text(){
		inputBuff="";
	    pos.currLine=1;
	    pos.x=0;
	    pos.y=0;
	}
	void initialize();
};