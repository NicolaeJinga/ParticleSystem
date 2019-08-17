#ifndef __PARTICLESYSTEM__H__
#define __PARTICLESYSTEM__H__

#include <vector>
#include "Particle.h"
#include "ParticleSpawner.h"

class ParticleSystem
{
protected:
	std::vector<Particle*> m_particle;
	std::vector<sf::Texture> m_texture;	
	ParticleSpawner* m_spawner;
	sf::Vector2f m_origin;
	int m_maxParticles;

	bool m_loop;
	float m_lifetime;
	float m_elapsedLifetime;

	float m_particleSpawnFrequency;
	bool m_isPlaying;
	float m_lastSpawnTime;
	float m_currentSpawnTime;

public:
	ParticleSystem(sf::Vector2f origin, int maxParticles, float particleSpawnFrequency, float lifetime);
	~ParticleSystem();
	void setSpawner(ParticleSpawner* spawner);
	void setOrigin(sf::Vector2f origin);
	void setMaxParticles(int maxParticles);
	void setParticleSpawnFrequency(float frequency);
	sf::Vector2f getOrigin();
	void play(bool loop);
	void stop();
	void setPlayParameters(float lifetime);
	virtual void update(float dt);
	virtual void draw(sf::RenderTarget& renderTarget);
};



#endif //__PARTICLESYSTEM__H__