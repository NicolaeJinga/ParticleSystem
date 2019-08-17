#include "SparkParticleSystem.h"
#include "SparkParticleSpawner.h"


SparkParticleSystem::SparkParticleSystem(sf::Vector2f origin, int maxParticles, float particleSpawnFrequency, float lifetime)
	: ParticleSystem(origin, maxParticles, particleSpawnFrequency, lifetime)
{
	m_spawner = new SparkParticleSpawner();
	m_spawner->setSpawner(sf::Vector2f(), 0 * pi / 180, 360 * pi / 180, 70, 90, 1);
	setOrigin(origin);
	setMaxParticles(maxParticles);
	setParticleSpawnFrequency(particleSpawnFrequency);
	setPlayParameters(lifetime);
}