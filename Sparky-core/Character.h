#pragma once
#include <glm/glm.hpp>
#include <Bengine/SpriteBatch.h>
#include <string>
#include <vector>
#include "Bullet.h"
#include "level.h"
#include "BrickExplode.h"


const int MIN_WALL_DISTANCE = 20;         // the minimum distance upto which a player can do near the bricks or the wall.

	class Character                       // This class defines the character attributes.
	{
	public:
		Character(std::string name, glm::vec2 pos, int person, glm::vec2 dim, int speed, int choice , const std::vector<std::string>& levelData);
		~Character();
		void init();
		void draw(Bengine::SpriteBatch& spriteBatch);
		void PlayerDead();
		//returns true if the player is alive else false
		bool isAlive() { return alive; }
		
		// for motion of character
		void moveUP(std::vector<BrickExplode> &_bricks, std::vector<glm::vec2> _brickFixedPos);
		void moveDOWN(std::vector<BrickExplode> &_bricks, std::vector<glm::vec2> _brickFixedPos);
		void moveRIGHT(std::vector<BrickExplode> &_bricks , std::vector<glm::vec2> _brickFixedPos);
		void moveLEFT(std::vector<BrickExplode> &_bricks, std::vector<glm::vec2> _brickFixedPos);
		bool damageTaken(int damage);

		// to set in the transferred string the index of the brick we are going to explode
		void setBrickToPop(int index);


		//getters
		
		glm::vec2 getPosition() { return (m_position + glm::vec2(m_dim.x / 2, m_dim.y / 2)); }	//dimension added to get position of the centre of the character
		float getHealth() { return m_health; }
		glm::vec2 getDim() { return m_dim; }
		
		std::string getData();

		//setters

		void setData(float x, float y, float health);
		void increaseScore();
		int getScore() { return score; }
		void setLife(bool set) { alive = set; }
	private:
		int score;
		bool alive;
		glm::vec2 m_position, m_dim;
		glm::vec4 m_uv = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
		Bengine::Color m_color = { 255,255,255,255 };
		std::string m_name;
		int m_person;
		GLuint m_texId[2];			//stores textures id
		int m_speed;
		float m_health = 200;		// the initial health of each character
		int m_score = 0;
		int m_choice;
		// contains the level data in form of vector of strings
		std::vector<std::string> m_levelData;
		// characters filepath
		std::string m_filePaths[6] = { "../Sparky-core/Textures/Characters/black.png","../Sparky-core/Textures/Characters/silver.png","../Sparky-core/Textures/Characters/bronze.png","../Sparky-core/Textures/Characters/grey.png","../Sparky-core/Textures/Characters/archer.png","../Sparky-core/Textures/Characters/wizard.png" };
	};

