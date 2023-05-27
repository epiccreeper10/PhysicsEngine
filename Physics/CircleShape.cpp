#include "CircleShape.h"
#include "Graphics.h"

void CircleShape::Draw(Graphics* Graphics, const glm::vec2& position)
{
	Graphics->DrawFilledCircle(position, (int)radius, color);
}
