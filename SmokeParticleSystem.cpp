#include "SmokeParticleSystem.h"
#include "SmokeParticleSpawner.h"


SmokeParticleSystem::SmokeParticleSystem(sf::Vector2f origin, int maxParticles, float particleSpawnFrequency, float lifetime) 
	: ParticleSystem(origin, maxParticles, particleSpawnFrequency, lifetime)
{
	m_spawner = new SmokeParticleSpawner();
	m_spawner->setSpawner(sf::Vector2f(),-70*pi/180,-120*pi/180,10,20,8);
	setOrigin(origin);
	setMaxParticles(maxParticles);
	setParticleSpawnFrequency(particleSpawnFrequency);
	setPlayParameters(lifetime);
}