#include "ParticleSystem.h"
#include "ParticleSpawner.h"

ParticleSystem::ParticleSystem(sf::Vector2f origin, int maxParticles, float particleSpawnFrequency, float lifetime) :
	m_isPlaying(false),
	m_elapsedLifetime(0.0f)
{
	m_spawner = new ParticleSpawner();
	m_spawner->setSpawner(sf::Vector2f(),0,0,0,0,0);
}

ParticleSystem::~ParticleSystem()
{
	for(unsigned int i=0; i < m_particle.size(); i++)
		delete m_particle[i];
	delete m_spawner;
}

void ParticleSystem::setOrigin(sf::Vector2f origin)
{
	m_origin = origin;
	if(m_spawner!=NULL)
		m_spawner->setOrigin(m_origin);
}

sf::Vector2f ParticleSystem::getOrigin()
{
	return m_origin;
}

void ParticleSystem::setMaxParticles(int maxParticles)
{
	m_maxParticles = maxParticles;
	if(m_particle.size() < (unsigned int)m_maxParticles)
		m_particle.resize(m_maxParticles, NULL);
	if(m_particle.size() > (unsigned int)m_maxParticles)
	{
		for(unsigned int i = m_maxParticles; i < m_particle.size(); i++)
			delete m_particle[i];
		m_particle.resize(m_maxParticles);
	}
}

void ParticleSystem::setParticleSpawnFrequency(float frequency)
{
	m_particleSpawnFrequency = frequency;
}

void ParticleSystem::setSpawner(ParticleSpawner* spawner)
{
	if(m_spawner != NULL)
		delete m_spawner;
	m_spawner = spawner;
	m_spawner->setOrigin(m_origin);
}

void ParticleSystem::play(bool loop)
{
	m_loop = loop;
	m_isPlaying = true;
	m_lastSpawnTime = 0;
	m_currentSpawnTime = 0;
}

void ParticleSystem::stop()
{
	m_isPlaying = false;
}

void ParticleSystem::setPlayParameters(float lifetime)
{
	m_lifetime = lifetime;
}

void ParticleSystem::update(float dt)
{
	for(std::vector<Particle*>::iterator currentParticle = m_particle.begin(); currentParticle!=m_particle.end(); currentParticle++)
	{
		if((*currentParticle)!=NULL)
		{
			(*currentParticle)->update(dt);
			if(!(*currentParticle)->isAlive())
			{
				delete (*currentParticle);
				(*currentParticle) = NULL;
			}
		}
	}
	if(m_isPlaying)
	{	
		m_currentSpawnTime += dt;
		float particleSpawnPeriod = 1.0f/m_particleSpawnFrequency;
		if(m_spawner!=NULL)
		{
			while(m_lastSpawnTime + particleSpawnPeriod <= m_currentSpawnTime )
			{
				for(unsigned int i = 0 ; i < m_particle.size(); i++)
					if(m_particle[i] == NULL)
					{
						m_particle[i]=m_spawner->spawn();
						break;
					}
				m_lastSpawnTime += particleSpawnPeriod;
			}
		}
		m_elapsedLifetime += dt;
		if(m_elapsedLifetime > m_lifetime && m_loop == false)
			stop();
	}
}

void ParticleSystem::draw(sf::RenderTarget& renderTarget)
{
	for(std::vector<Particle*>::iterator currentParticle = m_particle.begin(); currentParticle!=m_particle.end(); currentParticle++)
	{
		if((*currentParticle)!=NULL)
		{
			(*currentParticle)->draw(renderTarget);
		}
	}
}