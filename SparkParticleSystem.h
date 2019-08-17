#ifndef __SPARKPARTICLESYSTEM__H__
#define __SPARKPARTICLESYSTEM__H__

#include "ParticleSystem.h"

class SparkParticleSystem : public ParticleSystem
{
public:
	SparkParticleSystem(sf::Vector2f origin, int maxParticles, float particleSpawnFrequency, float lifetime);
};



#endif // __SPARKPARTICLESYSTEM__H__
