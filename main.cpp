#include "Particle.h"
#include "SFML\Graphics.hpp"
#include "ParticleSystem.h"
#include "SmokeParticleSystem.h"
#include "WaterParticleSystem.h"
#include "SparkParticleSystem.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600),"ParticleSystem");
	sf::Event event;
	sf::Clock frameTime;

	std::vector<ParticleSystem*> particleSystems;

	particleSystems.push_back(new SmokeParticleSystem(sf::Vector2f(window.getSize().x * 1.0f / 4.0f, window.getSize().y / 2.0f), 500, 10, 5));
	particleSystems.push_back(new SmokeParticleSystem(sf::Vector2f(window.getSize().x * 1.0f / 4.0f - 10.0f, window.getSize().y / 2.0f), 500, 10, 8));
	particleSystems.push_back(new SmokeParticleSystem(sf::Vector2f(window.getSize().x * 1.0f / 4.0f + 10.0f, window.getSize().y / 2.0f), 500, 20, 11));

	particleSystems.push_back(new WaterParticleSystem(sf::Vector2f(window.getSize().x * 3.0f / 4.0f, window.getSize().y / 2.0f), 500, 60, 10));
	particleSystems.push_back(new WaterParticleSystem(sf::Vector2f(window.getSize().x * 3.0f / 4.0f + 10.0f, window.getSize().y / 2.0f), 500, 55, 10));
	particleSystems.push_back(new WaterParticleSystem(sf::Vector2f(window.getSize().x * 3.0f / 4.0f - 10.0f, window.getSize().y / 2.0f), 500, 55, 10));

	particleSystems.push_back(new SparkParticleSystem(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f), 500, 100, 1));

	for (size_t i = 0; i < particleSystems.size(); ++i)
	{
		particleSystems[i]->play(true);
	}

	float dt = 0.0f;
	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		dt = frameTime.getElapsedTime().asSeconds();
		frameTime.restart();
		
		//update
		for (size_t i = 0; i < particleSystems.size(); ++i)
		{
			particleSystems[i]->update(dt);
		}

		//draw
		window.clear();
		for (size_t i = 0; i < particleSystems.size(); ++i)
		{
			particleSystems[i]->draw(window);
		}
		window.display();
	}

}