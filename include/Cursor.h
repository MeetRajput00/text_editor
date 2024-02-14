#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "../common/common_includes.h"

class Cursor{
public:
	void initialize(sf::Text *text);
private:
	bool showCursor = true;
	sf::RectangleShape cursor;
};