# Zork Inspired Game

## Synopsis

Your character is unfairly jailed in a medieval prison. You have to find a way to get out of it, will you dare to find your way out? or will you perish in the hands of terrible guards?

## Author
Daniel Pérez Paraíso  
GitHub link: https://github.com/DperParadise/Zork   

## Accepted commands

H: Shows you a list of accepted commands in game  
I: Shows your inventory  
Q: Quit Menu. You can either restart or quit the game.  
TAKE "item": you pick up "item".  
DROP "item": you drop the "item" right where you are.  
PUT "something/someone" INTO "something": punt one item into another.  
HIT "something/someone": you hit a person or a thing.  
LOOK "something/someone": you carefully look at someone/something.  
SEARCH "someone": you search someone's belongings.  
OPEN "something".   
CLOSE "something".  
USE "something".  
COMBINE "something" WITH "something".  
DETACH "something" FROM "something": splits two combined objects.  

## Map

![prsion map](https://i.imgsafe.org/8cd1dc2bde.jpg)

## Gameplay guide ( spoiler!!! )   

The game has two exits.  
**Exit 1 commands sequence**  

**Start: CELL**   
LOOK window  
TAKE bar  
TAKE breadcrumbs  
USE breadcrumbs WITH window  
TAKE pigeon  
USE pigeon WITH opening  
HIT guard  
SEARCH guard  
TAKE cell key  
DROP bar  
DROP breadcrumbs  
GO east  

**Start: AISLE 1**  
TAKE chair  
OPEN door  

**Start: AISLE 2**    
OPEN north door  

**Start: GUARDROOM**    
OPEN small closet  
TAKE cleaning staff key  
TAKE armory key   
GO south  

**Start: AISLE 2**    
OPEN south door  

**Start: ARMORY**    
USE chair  
TAKE shield   
TAKE sword   
DROP armory key   
GO north  

**Start: AISLE 2**     
GO east   

**Start: AISLE 3**       
GO south  

**Start: TOOLROOM**    
HIT guard   
OPEN closet   
TAKE rope   
TAKE mace   
GO north   

**Start: AISLE 3  (Here starts Exit 2 sequence )**     
GO west   

**Start: AISLE 2**     
GO west   

**Start: AISLE 1**     
GO west   

**Start: CELL**     
HIT window   
USE rope WITH sword   
USE rope  

You are free in the woods.   

**Exit 2 commands sequence**  
Repeat steps from the first sequence until Start: AISLE 3   

**Start: AISLE 3**   
GO north    
Start: UPSTAIRS FLOOR   
OPEN west door   
Start: GUARDS BEDROOM   
HIT guard   
TAKE leather cuirass   
TAKE helmet   
GO east   

**Start: UPSTAIRS FLOOR**    
OPEN north door   

**Start: MEETINGS ROOM**      
HIT officer   
DROP cleaning staff key   
GO south   

**Start: UPSTAIRS FLOOR**     
GO west   

**Start: GUARDS BEDROOM**     
LOOK wardrobe   
TAKE clothes   
SEARCH guard   
DROP helmet   
TAKE bag of coins   
GO east   

**Start: UPSTAIRS FLOOR**     
GO east   

**Start: MAIN HALL**     
OPEN door  

You are free on the street.

## License   

This software is licensed under: [GNU GENERAL PUBLIC LICENSE](https://www.gnu.org/licenses/gpl-3.0.txt)   
