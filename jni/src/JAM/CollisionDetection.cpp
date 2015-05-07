#include "CollisionDetection.h"

/**************************************************************************************************************/

/*CollisionDetection between two rectangles.*/
bool JAM_CollisionDetection::collisionRectRectDetection(JAM_Vec2 positionA, JAM_Vec2 dimensionsA, JAM_Vec2 positionB, JAM_Vec2 dimensionsB)
{
	/*test for intersection*/
	if ((positionA.x > positionB.x + dimensionsB.x - 1) || /*check if object 1 is to the right of object 2*/
		(positionA.y > positionB.y + dimensionsB.y - 1) || /*check if object 1 is under object 2*/
		(positionB.x > positionA.x + dimensionsA.x - 1) || /*check if object 2 is to the right of object 1*/
		(positionB.y > positionA.y + dimensionsA.y - 1))   /*check if object 2 is under object 1*/
	{
		/*no collision*/
		return false;
	}

	/*collision*/
	return true;
}

/**************************************************************************************************************/

/*CollisionDetection for between circles.*/
bool JAM_CollisionDetection::collisionCircleCircleDetection(JAM_Vec2 positionA, float radiusA, JAM_Vec2 positionB, float radiusB)
{
	/*get the size of the two radius's combined for the maximum distance without intersection*/
	float maxDistance = radiusA + radiusB;

	/*work out the difference in the coordinates of the two circles*/
	float deltaX = positionA.x - positionB.x;
	float deltaY = positionA.y - positionB.y;

	/*sqrt (dX^2 + dY^2)*/
	float distance = sqrtf((deltaX * deltaX) + (deltaY * deltaY));

	/*check if the distance is less than the max distance*/
	if (distance < maxDistance)
	{
		/*collision*/
		return true;
	}

	/*no collision*/
	return false;
}