#include "SmokeParticle.h"

void SmokeParticle::draw(sf::RenderTarget& renderTarget)
{
	float t = m_lifetimeRemaining / m_maxLifetime;
	m_sprite.setColor(sf::Color(255,255,255,(sf::Uint8)(pow(t,0.25)*255)));
	m_sprite.setPosition(m_position);
	renderTarget.draw(m_sprite);
}