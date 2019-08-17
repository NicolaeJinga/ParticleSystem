#include "SparkParticleSpawner.h"

SparkParticleSpawner::SparkParticleSpawner()
{
	m_texture = new sf::Texture();
	m_texture->loadFromFile("SparkParticle.png");
}