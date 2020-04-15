<?xml version="1.0" encoding="UTF-8"?>
<tileset name="Buttons" tilewidth="128" tileheight="128" tilecount="4" columns="2">
 <image source="buttons.png" width="256" height="256"/>
 <tile id="0" type="Button">
  <properties>
   <property name="ACTOR_NAME" value="QuitButton"/>
   <property name="ANIMATION_TYPE" value="IDLE"/>
   <property name="id" value="Quit"/>
  </properties>
  <objectgroup draworder="index">
   <object id="1" x="5" y="42" width="117" height="39"/>
  </objectgroup>
 </tile>
 <tile id="1" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="QuitButton"/>
   <property name="ANIMATION_TYPE" value="IDLE"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
  <animation>
   <frame tileid="0" duration="1000"/>
   <frame tileid="1" duration="1000"/>
  </animation>
 </tile>
 <tile id="2" type="Button">
  <properties>
   <property name="ACTOR_NAME" value="StartButton"/>
   <property name="ANIMATION_TYPE" value="IDLE"/>
   <property name="id" value="Start"/>
  </properties>
  <objectgroup draworder="index">
   <object id="1" x="5" y="42" width="117" height="39"/>
  </objectgroup>
 </tile>
 <tile id="3" type="ACTOR_ANIMATION">
  <properties>
   <property name="ACTOR_NAME" value="StartButton"/>
   <property name="ANIMATION_TYPE" value="IDLE"/>
   <property name="DIRECTION" value="NONE"/>
  </properties>
  <animation>
   <frame tileid="2" duration="1000"/>
   <frame tileid="3" duration="1000"/>
  </animation>
 </tile>
</tileset>
