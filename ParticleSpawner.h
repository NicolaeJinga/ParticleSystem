#ifndef __PARTICLESPAWNER__H__
#define __PARTICLESPAWNER__H__

#include "Particle.h"

const float pi = 3.141592f;

class ParticleSpawner
{
protected:
	sf::Vector2f m_spawnPoint;
	sf::Vector2f m_origin;
	float m_startAngle;
	float m_endAngle;
	float m_minSpeed;
	float m_maxSpeed;
	float m_lifetime;
	sf::Texture* m_texture;

public:
	ParticleSpawner();
	~ParticleSpawner();
	void setSpawner(sf::Vector2f spawnPoint, float startAngle, float endAngle, float minSpeed, float maxSpeed, float lifetime);
	void setSpawnPoint(sf::Vector2f spawnPoint);
	void setTexture(sf::Texture* texture);
	Particle* spawn();
	void setOrigin(sf::Vector2f origin);
};



#endif //__PARTICLESPAWNER__H__