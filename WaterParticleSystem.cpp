#include "WaterParticleSystem.h"
#include "WaterParticleSpawner.h"


WaterParticleSystem::WaterParticleSystem(sf::Vector2f origin, int maxParticles, float particleSpawnFrequency, float lifetime)
	: ParticleSystem(origin, maxParticles, particleSpawnFrequency, lifetime)
{
	m_spawner = new WaterParticleSpawner();
	m_spawner->setSpawner(sf::Vector2f(), 85 * pi / 180, 95 * pi / 180, 50, 70, 8);
	setOrigin(origin);
	setMaxParticles(maxParticles);
	setParticleSpawnFrequency(particleSpawnFrequency);
	setPlayParameters(lifetime);
}