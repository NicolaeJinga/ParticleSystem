#include "SmokeParticleSpawner.h"

SmokeParticleSpawner::SmokeParticleSpawner()
{
	m_texture = new sf::Texture();
	m_texture->loadFromFile("SmokeParticle.png");
}