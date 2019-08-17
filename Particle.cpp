#include "Particle.h"
#include <SFML/Graphics.hpp>


Particle::Particle()
{
}

Particle::~Particle()
{
}

Particle::Particle(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f acceleration, float lifetimeRemaining, sf::Texture* texture):
	m_alive(true),
	m_position(position),
	m_velocity(velocity),
	m_acceleration(acceleration),
	m_lifetimeRemaining(lifetimeRemaining),
	m_maxLifetime(lifetimeRemaining)

{
	m_sprite.setPosition(m_position);
	m_sprite.setTexture(*texture);
	m_sprite.setOrigin(texture->getSize().x/2.0f,texture->getSize().y/2.0f);
}

void Particle::init(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f acceleration, float lifetimeRemaining)
{
	m_alive = true;
	m_position = position;
	m_velocity = velocity;
	m_acceleration = acceleration;
	m_lifetimeRemaining = lifetimeRemaining;
	m_maxLifetime = lifetimeRemaining;
	m_sprite.setPosition(m_position);
}

bool Particle::isAlive()
{
	return m_alive;
}

void Particle::setSize(float size) // pixeli (width = height);
{
	float scaleFactor = size/m_sprite.getLocalBounds().width;
	m_sprite.setScale(scaleFactor,scaleFactor);
}

void Particle::setVelocity(sf::Vector2f velocity)
{
	m_velocity = velocity;
}

void Particle::setAcceleration(sf::Vector2f acceleration)
{
	m_acceleration = acceleration;
}

const sf::Vector2f& Particle::getVelocity()
{
	return m_velocity;
}

void Particle::update(float dt)
{
	m_lifetimeRemaining -= dt;
	m_alive = m_lifetimeRemaining > 0;
	m_velocity += m_acceleration* dt;
	m_position += m_velocity * dt;

}

void Particle::draw(sf::RenderTarget& renderTarget)
{
	m_sprite.setPosition(m_position);
	renderTarget.draw(m_sprite);
}