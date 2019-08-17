#ifndef __SMOKEPARTICLESYSTEM__H__
#define __SMOKEPARTICLESYSTEM__H__

#include "ParticleSystem.h"

class SmokeParticleSystem : public ParticleSystem
{
public:
	SmokeParticleSystem(sf::Vector2f origin, int maxParticles, float particleSpawnFrequency, float lifetime);
};



#endif // __SMOKEPARTICLESYSTEM__H__
