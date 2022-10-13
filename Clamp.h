#pragma once

float ClampX(float preX, float worldX, float rX, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY);
float HitX(float preX, float worldX, float rX, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float hit);

float ClampShotX(float preX, float worldX, float rX, float preY, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float shotVelocityX, float isGround);
float ClampShotY(float preX, float worldX, float rX, float preY, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float shotVelocityY, float isGround);
float notUpClampShotX(float preX, float worldX, float rX, float preY, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float shotVelocityX, float isGround);
float notUpClampShotY(float preX, float worldX, float rX, float preY, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float shotVelocityY, float isGround);
float spClampShotX(float preX, float worldX, float rX, float preY, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float shotVelocityX, float isGround);
float spClampShotY(float preX, float worldX, float rX, float preY, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float shotVelocityY, float isGround);
float ClampReflectX(float preX, float worldX, float rX, float preY, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float shotVelocityX);
float ClampEnemyReflectX(float preX, float worldX, float rX, float preY, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float shotVelocityX);
float ClampReflectY(float preX, float worldX, float rX, float preY, float worldY, float rY, float terrainLeftX, float terrainRightX, float terrainHighY, float terrainLowY, float shotVelocityY, float isGround);


float ClampY(float preY, float worldY, float rY, float worldX, float rX, float terrainHighY, float terrainLowY, float terrainLeftX, float terrainRightX);
float spClampY(float preY, float worldY, float rY, float worldX, float rX, float terrainHighY, float terrainLowY, float terrainLeftX, float terrainRightX);
float ClampGround(float preY, float worldY, float rY, float worldX, float rX, float terrainHighY, float terrainLowY, float terrainLeftX, float terrainRightX, float ground);
float ClampVelocityY(float preY, float worldY, float rY, float worldX, float rX, float terrainHighY, float terrainLowY, float terrainLeftX, float terrainRightX, float velocityY);
float spClampVelocityY(float preY, float worldY, float rY, float worldX, float rX, float terrainHighY, float terrainLowY, float terrainLeftX, float terrainRightX, float velocityY);

