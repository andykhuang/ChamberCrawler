CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = cc3k
OBJECTS = main.o abstractpotion.o blanktile.o boostatk.o boostdef.o chamber.o character.o doorway.o dragon.o dragontreasure.o drow.o dwarf.o elf.o emptypotion.o enemy.o floor.o floortile.o game.o goblin.o human.o item.o merchant.o orc.o passage.o player.o poisonhealth.o potion.o restorehealth.o shade.o stairs.o tile.o treasure.o troll.o vampire.o wall.o woundatk.o wounddef.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
