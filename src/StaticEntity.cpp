#include "StaticEntity.h"

StaticEntity::StaticEntity( float x , float y , int w = 0 , int h = 0 )
{
    position.x = x;
	position.y = y;
    windowRect.w = w;
    windowRect.h = h;
	adjustRectPosition();
}

StaticEntity::StaticEntity( int w , int h )
{
    windowRect.w = w;
    windowRect.h = h;
	adjustRectPosition();
}

StaticEntity::~StaticEntity() { }

void StaticEntity::adjustRectPosition()
{
	windowRect.x = floor( ( ( position.x - scenario.rect.x ) ) - ( windowRect.w ) );
    windowRect.y = floor( ( ( position.y - scenario.rect.y ) ) - ( windowRect.h ) );
    
    mapLocator = scenario.map[(int)position.x - (int)position.x%100]
		    [(int)position.y - (int)position.y%100];
}
void StaticEntity::adjustRectSprite()
{
    windowRect.x = ( position.x - ( windowRect.w / 2 ) );
    windowRect.y = ( position.y - ( windowRect.h / 2 ) );
}
