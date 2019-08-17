#include "SparkParticle.h"

void SparkParticle::draw(sf::RenderTarget& renderTarget)
{
	float t = m_lifetimeRemaining / m_maxLifetime;
	m_sprite.setPosition(m_position);
	renderTarget.draw(m_sprite);
}