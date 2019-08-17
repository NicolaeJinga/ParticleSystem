#include "ParticleSpawner.h"
#include "Particle.h"
#include <stdlib.h>
#include <math.h>

ParticleSpawner::ParticleSpawner()
{
	m_startAngle = 0;
	m_endAngle = 2*pi;
	m_minSpeed = 0;
	m_maxSpeed = 1;
	m_texture = NULL;
}

ParticleSpawner::~ParticleSpawner()
{
	if(m_texture!=NULL)
		delete m_texture;
}

Particle* ParticleSpawner::spawn()
{
	if(m_texture == NULL)
		return NULL;
	float speed = m_minSpeed + (rand() / (float) RAND_MAX)*(m_maxSpeed-m_minSpeed);
	float alfa = m_startAngle + (rand() / (float) RAND_MAX)*(m_endAngle-m_startAngle);
	sf::Vector2f velocity(speed*cos(alfa), speed*sin(alfa));
	return new Particle(m_origin + m_spawnPoint, velocity, sf::Vector2f() , m_lifetime, m_texture);
}

void ParticleSpawner::setTexture(sf::Texture* texture)
{
	m_texture = texture;
}

void ParticleSpawner::setSpawner(sf::Vector2f spawnPoint, float startAngle, float endAngle, float minSpeed, float maxSpeed, float lifetime)
{
	m_spawnPoint = spawnPoint;
	m_startAngle = startAngle;
	m_endAngle = endAngle;
	m_minSpeed = minSpeed;
	m_maxSpeed = maxSpeed;
	m_lifetime = lifetime;
}

void ParticleSpawner::setSpawnPoint(sf::Vector2f spawnPoint)
{
	m_spawnPoint = spawnPoint;
}

void ParticleSpawner::setOrigin(sf::Vector2f origin)
{
	m_origin = origin;
}
