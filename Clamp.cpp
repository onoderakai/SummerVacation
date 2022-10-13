#include <stdio.h>
#include "Clamp.h"

float ClampX(float preX, float worldX, float rX, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY)
{
	if (preX <= terrainLeftX - rX) {
		if (worldX >= terrainLeftX - rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
			worldX = terrainLeftX - rX;
		}
	}
	else if (preX >= terrainRightX + rX) {
		if (worldX <= terrainRightX + rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
			worldX = terrainRightX + rX;
		}
	}
	return worldX;
}
float HitX(float preX, float worldX, float rX, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float hit)
{

	if (worldX <= terrainRightX + rX && worldX >= terrainLeftX - rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
		hit = 1.0f;
	}
	else {
		hit = 0.0f;
	}


	if (worldX <= terrainRightX + rX && worldX >= terrainLeftX - rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
		hit = 2.0f;
	}
	else {
		hit = 0.0f;
	}


	return hit;
}

float ClampShotX(float preX, float worldX, float rX, float preY, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float shotVelocityX, float isGround)
{
	if (preX <= terrainLeftX - rX) {
		if (worldX >= terrainLeftX - rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
			if (isGround) {
				shotVelocityX *= -0.5f;
			}
			else {
				shotVelocityX *= -0.3f;
			}
		}
	}
	else if (preX >= terrainRightX + rX) {
		if (worldX <= terrainRightX + rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
			if (isGround) {
				shotVelocityX *= -0.5f;
			}
			else {
				shotVelocityX *= -0.3f;
			}
		}
	}
	if (preY <= terrainHighY - rY) {
		if (worldY >= terrainHighY - rY && worldX > terrainLeftX - rX && worldX < terrainRightX + rX) {
			if (isGround) {
				shotVelocityX *= 1.0f;
			}
			else {
				shotVelocityX *= 0.5f;
			}
		}
	}
	else if (preY >= terrainLowY + rY) {
		if (worldY <= terrainLowY + rY && worldX > terrainLeftX - rX && worldX < terrainRightX + rX) {
			if (isGround) {
				shotVelocityX *= 1.0f;
			}
			else {
				shotVelocityX *= 0.5f;
			}
		}
	}

	return shotVelocityX;
}
float ClampReflectX(float preX, float worldX, float rX, float preY, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float shotVelocityX) {
	if (preX <= terrainLeftX - rX) {
		if (worldX >= terrainLeftX - rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
			shotVelocityX *= -1;
		}
	}
	else if (preX >= terrainRightX + rX) {
		if (worldX <= terrainRightX + rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
			shotVelocityX *= -1;
		}
	}
	return shotVelocityX;
}
float ClampEnemyReflectX(float preX, float worldX, float rX, float preY, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float shotVelocityX) {
	if (preX <= terrainLeftX - rX) {
		if (worldX >= terrainLeftX - rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
			shotVelocityX *= -1;
		}
	}
	else if (preX >= terrainRightX) {
		if (worldX <= terrainRightX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
			shotVelocityX *= -1;
		}
	}
	return shotVelocityX;
}

float ClampReflectY(float preX, float worldX, float rX, float preY, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float shotVelocityY, float isGround) {
	return shotVelocityY;
}

float ClampShotY(float preX, float worldX, float rX, float preY, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float shotVelocityY, float isGround)
{
	if (preX <= terrainLeftX - rX) {
		if (worldX >= terrainLeftX - rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
			if (isGround) {
				shotVelocityY *= 1.0f;
			}
			else {
				shotVelocityY = 0.0f;
			}
		}
	}
	else if (preX >= terrainRightX + rX) {
		if (worldX <= terrainRightX + rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
			if (isGround) {
				shotVelocityY *= 1.0f;
			}
			else {
				shotVelocityY = 0.0f;
			}
		}
	}
	if (preY <= terrainHighY - rY) {
		if (worldY >= terrainHighY - rY + 1 && worldX > terrainLeftX - rX && worldX < terrainRightX + rX) {
			if (isGround) {
				shotVelocityY *= -1.0f;
			}
			else {
				shotVelocityY *= -0.5f;
			}
		}
	}
	else if (preY >= terrainLowY + rY) {
		if (worldY <= terrainLowY + rY&& worldX > terrainLeftX - rX && worldX < terrainRightX + rX) {
			if (isGround) {
				shotVelocityY *= -1.0f;
			}
			else {
				shotVelocityY *= -0.5f;
			}
		}
	}

	return shotVelocityY;

}
float notUpClampShotX(float preX, float worldX, float rX, float preY, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float shotVelocityX, float isGround) {
	if (preX <= terrainLeftX - rX) {
		if (worldX >= terrainLeftX - rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
			if (isGround) {
				shotVelocityX *= -0.5f;
			}
			else {
				shotVelocityX *= -0.3f;
			}
		}
	}
	else if (preX >= terrainRightX + rX) {
		if (worldX <= terrainRightX + rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
			if (isGround) {
				shotVelocityX *= -0.5f;
			}
			else {
				shotVelocityX *= -0.3f;
			}
		}
	}
	if (preY >= terrainLowY + rY) {
		if (worldY <= terrainLowY + rY && worldX > terrainLeftX - rX && worldX < terrainRightX + rX) {
			if (isGround) {
				shotVelocityX *= 1.0f;
			}
			else {
				shotVelocityX *= 0.5f;
			}
		}
	}

	return shotVelocityX;
}
float notUpClampShotY(float preX, float worldX, float rX, float preY, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float shotVelocityY, float isGround) {
	if (preX <= terrainLeftX - rX) {
		if (worldX >= terrainLeftX - rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
			if (isGround) {
				shotVelocityY *= 1.0f;
			}
			else {
				shotVelocityY = 0.0f;
			}
		}
	}
	else if (preX >= terrainRightX + rX) {
		if (worldX <= terrainRightX + rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
			if (isGround) {
				shotVelocityY *= 1.0f;
			}
			else {
				shotVelocityY = 0.0f;
			}
		}
	}
	if (preY >= terrainLowY + rY) {
		if (worldY <= terrainLowY + rY && worldX > terrainLeftX - rX && worldX < terrainRightX + rX) {
			if (isGround) {
				shotVelocityY *= -1.0f;
			}
			else {
				shotVelocityY *= -0.5f;
			}
		}
	}

	return shotVelocityY;

}

float spClampShotX(float preX, float worldX, float rX, float preY, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float shotVelocityX, float isGround) {
	if (preX <= terrainLeftX - rX) {
		if (worldX >= terrainLeftX - rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
			if (isGround) {
				shotVelocityX *= -1.0f;
			}
			else {
				shotVelocityX *= -0.3f;
			}
		}
	}
	else if (preX >= terrainRightX + rX) {
		if (worldX <= terrainRightX + rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
			if (isGround) {
				shotVelocityX *= -1.0f;
			}
			else {
				shotVelocityX *= -0.3f;
			}
		}
	}
	if (preY <= terrainHighY - rY) {
		if (worldY >= terrainHighY - rY && worldX > terrainLeftX - rX && worldX < terrainRightX + rX) {
			if (isGround) {
				shotVelocityX *= 1.0f;
			}
			else {
				shotVelocityX *= 0.5f;
			}
		}
	}

	return shotVelocityX;
}
float spClampShotY(float preX, float worldX, float rX, float preY, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float shotVelocityY, float isGround) {
	if (preX <= terrainLeftX - rX) {
		if (worldX >= terrainLeftX - rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
			if (isGround) {
				shotVelocityY *= 1.0f;
			}

		}
	}
	else if (preX >= terrainRightX + rX) {
		if (worldX <= terrainRightX + rX && worldY > terrainHighY - rY && worldY < terrainLowY + rY) {
			if (isGround) {
				shotVelocityY *= 1.0f;
			}

		}
	}
	if (preY <= terrainHighY - rY) {
		if (worldY >= terrainHighY - rY && worldX > terrainLeftX - rX && worldX < terrainRightX + rX) {
			if (isGround) {
				shotVelocityY *= -1.0f;
			}
			else {
				shotVelocityY *= -0.1f;
			}
		}
	}

	return shotVelocityY;
}


float ClampY(float preY, float worldY, float rY, float worldX, float rX, float terrainHighY, float terrainLowY, float terrainLeftX, float terrainRightX) {
	if (preY <= terrainHighY - rY) {
		if (worldY >= terrainHighY - rY && worldX > terrainLeftX - rX && worldX < terrainRightX + rX) {
			worldY = terrainHighY - rY;
		}
	}
	else if (preY >= terrainLowY + rY) {
		if (worldY <= terrainLowY + rY && worldX > terrainLeftX - rX && worldX < terrainRightX + rX) {
			worldY = terrainLowY + rY;
		}
	}

	return worldY;
}
float spClampY(float preY, float worldY, float rY, float worldX, float rX, float terrainHighY, float terrainLowY, float terrainLeftX, float terrainRightX) {
	if (preY <= terrainHighY - rY) {
		if (worldY >= terrainHighY - rY && worldX > terrainLeftX - rX && worldX < terrainRightX + rX) {
			worldY = terrainHighY - rY;
		}
	}

	return worldY;
}
float ClampGround(float preY, float worldY, float rY, float worldX, float rX, float terrainHighY, float terrainLowY, float terrainLeftX, float terrainRightX, float ground) {
	if (preY <= terrainHighY - rY) {
		if (worldY >= terrainHighY - rY && worldX > terrainLeftX - rX && worldX < terrainRightX + rX) {
			ground = 1;
		}
	}
	else if (preY < worldY) {
		ground = 0;
	}

	return ground;
}
float ClampVelocityY(float preY, float worldY, float rY, float worldX, float rX, float terrainHighY, float terrainLowY, float terrainLeftX, float terrainRightX, float velocityY) {
	if (preY <= terrainHighY - rY) {
		if (worldY >= terrainHighY - rY && worldX > terrainLeftX - rX && worldX < terrainRightX + rX) {
			velocityY = 0.0f;
		}
	}
	if (preY >= terrainLowY + rY) {
		if (worldY <= terrainLowY + rY && worldX > terrainLeftX - rX && worldX < terrainRightX + rX) {
			worldY = terrainLowY + rY;
			velocityY = 0.0f;
		}
	}

	return velocityY;
}
float spClampVelocityY(float preY, float worldY, float rY, float worldX, float rX, float terrainHighY, float terrainLowY, float terrainLeftX, float terrainRightX, float velocityY) {
	if (preY <= terrainHighY - rY) {
		if (worldY >= terrainHighY - rY && worldX > terrainLeftX - rX && worldX < terrainRightX + rX) {
			velocityY = 0.0f;
		}
	}

	return velocityY;
}