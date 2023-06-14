#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>

using sf::Text;
using sf::Font;
using sf::Texture;
using sf::Sprite;
using sf::RectangleShape;
using sf::CircleShape;
using sf::RenderWindow;
using sf::VideoMode;
using sf::Clock;
using sf::Time;
using sf::IntRect;
using sf::FloatRect;
using sf::Vector2f;
using sf::Vector2i;
using sf::Event;
using sf::Color;
using sf::Mouse;
using sf::Keyboard;
using sf::Music;
using sf::Sound;
using sf::SoundBuffer;

using std::vector;
using std::map;
using std::pair;
using std::string;
using std::to_string;
using std::remove;
using std::runtime_error;
using std::unique_ptr;

#define DISABLE_TASKBAR TRUE
#define ENABLE_CONSOLE TRUE
#define DEBUGGING TRUE

const string GAME_TITLE = "The Purge";

const int WINDOW_X = 800;
const int WINDOW_Y = 600;
const int FRAMERATE_LIMIT = 60;

const float M_PI = 3.14159265358979323846;