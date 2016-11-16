# Zork Inspired Game

## Synopsis

Your character is unfairly jailed in a medieval prison. You have to find a way to get out of it. Will you dare to find your way out? or will you perish in the hands of terrible guards?

## Author
Daniel Pérez Paraíso  
GitHub link: https://github.com/DperParadise/Zork   

## Accepted commands

**H**: Shows you a list of accepted commands in game  
**I**: Shows your inventory  
**Q**: Quit Menu. You can either restart or quit the game.  
**TAKE** "something/someone": you pick up "something/someone".  
**DROP** "something/someone": you drop the item right where you are.  
**PUT** "something/someone" **INTO** "something": punt one item into another.  
**HIT** "something/someone": you hit a person or a thing.  
**LOOK** "something/someone": you carefully look at someone/something.  
**SEARCH** "someone": you search someone's belongings.  
**OPEN** "something".   
**CLOSE** "something".  
**USE** "something".  
**COMBINE** "something" **WITH** "something".  
**DETACH** "something" **FROM** "something": splits two combined objects.  
**GO NORTH**: move towards north.      
**N**: move towards north.      
**GO SOUTH**: move towards south.      
**S**: move towards south.      
**GO EAST**: move towards east.      
**E**: move towards east.      
**GO WEST**: move towards west.      
**W**: move towards west.         

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
TAKE sword   
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
DROP armory key   
GO north  

**Start: AISLE 2**     
GO east   

**Start: AISLE 3 (starting point for Exit 2 sequence )**       
GO south  

**Start: TOOLROOM**    
HIT guard  
DROP sword   
OPEN closet   
TAKE rope   
TAKE mace   
GO north   

**Start: AISLE 3**

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
Repeat steps from the first sequence until starting point for Exit 2      

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
