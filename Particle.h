#ifndef __PARTICLE__H__
#define __PARTICLE__H__

#include <SFML/Graphics.hpp>

class Particle
{
protected:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_acceleration;
	sf::Sprite m_sprite;
	bool m_alive;
	float m_lifetimeRemaining;
	float m_maxLifetime;

public:
	Particle();

	~Particle();

	Particle(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f acceleration, float lifetimeRemaining, sf::Texture* texture);
	
	void init(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f acceleration, float lifetimeRemaining);
	
	bool isAlive();

	// size is given in pixels (width = height);
	void setSize(float size); 

	void setVelocity(sf::Vector2f velocity);

	void setAcceleration(sf::Vector2f acceleration);

	const sf::Vector2f& getVelocity();

	virtual void update(float dt);

	virtual void draw(sf::RenderTarget& renderTarget);
	
};


#endif //__PARTICLE__H__