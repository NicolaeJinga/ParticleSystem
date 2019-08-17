#include "WaterParticleSpawner.h"

WaterParticleSpawner::WaterParticleSpawner()
{
	m_texture = new sf::Texture();
	m_texture->loadFromFile("WaterParticle.png");
}