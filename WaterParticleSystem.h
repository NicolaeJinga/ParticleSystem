#ifndef __WATERPARTICLESYSTEM__H__
#define __WATERPARTICLESYSTEM__H__

#include "ParticleSystem.h"

class WaterParticleSystem : public ParticleSystem
{
public:
	WaterParticleSystem(sf::Vector2f origin, int maxParticles, float particleSpawnFrequency, float lifetime);
};



#endif // __WATERPARTICLESYSTEM__H__
