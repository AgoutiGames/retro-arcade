<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.2" tiledversion="1.3.3" name="snake" tilewidth="8" tileheight="8" tilecount="4" columns="2">
 <image source="snake.png" width="16" height="16"/>
 <tile id="0" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="Snake"/>
   <property name="ANIMATION_TYPE" value="Body"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
 </tile>
 <tile id="1" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="Snake"/>
   <property name="ANIMATION_TYPE" value="Head"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
 </tile>
 <tile id="2" type="Snake">
  <properties>
   <property name="ACTOR_ANIMATION" value="Head"/>
   <property name="ACTOR_NAME" value="Snake"/>
  </properties>
  <objectgroup draworder="index" id="2">
   <object id="1" x="0" y="0" width="8" height="8"/>
  </objectgroup>
 </tile>
 <tile id="3" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="Snake"/>
   <property name="ANIMATION_TYPE" value="Tail"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
 </tile>
</tileset>
