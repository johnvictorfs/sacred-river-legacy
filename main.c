#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "struct.h"

int main(int argc, char *argv[]) {
	srand(time(NULL));
	
	// Stats iniciais (user)
	user.moedas = 5;
	user.hp = 10;
	user.defesa = 1;
	user.ataque = 2;
	
	// Stats (goblin)
	goblin.ataque = 3;
	goblin.defesa = 1;
	goblin.hp = 7;
	goblin.loot = 3;
	strcpy(goblin.nome,"Goblin");
	
	// Stats (aranha)
    aranha.ataque = 4;
    aranha.defesa = 2;
    aranha.hp = 8;
    aranha.loot = 5;
    strcpy(aranha.nome,"Aranha Gigante");
    
    // Stats (esqueleto)
    esqueleto.ataque = 6;
    esqueleto.defesa = 4;
    esqueleto.hp = 11;
    esqueleto.loot = 7;
    esqueleto.lootraro = 5;
    strcpy(esqueleto.nome,"Esqueleto");
	
	int res2,encontro1;
	char inicial,comando1,loja1,resposta1;

	/*
	Espada de Madeira // +5 ATK
	Espada de Ferro // + 10 ATK
	Espada de Aco // + 15 ATK
	Espada de Adamantio // +20 ATK

	Escudo de Madeira // +5 DEF
	Escudo de Ferro // + 15 DEF
	Escudo de Aco // + 22 DEF
	Escudo de Adamantio // + 31 DEF

	Lanca de Madeira // + 7 ATK
	Lanca de Ferro // + 20 ATK
	Lanca de Aco // + 25 ATK
	Lanca de Adamantio // + 35 ATK
	*/
	printf ("*** Bem vindo ao text-based RPG Sacred River ***\n\n"); // Mensagem inicial
	printf("Qual o seu nome?\n\n> ");
	scanf("%s",&user.nome); // Pede input do usuário e armazena em 'user.nome'
	fflush(stdin); // Impede input desse 'scanf' ser usada em 'scanf' seguidos
	Sleep(500); // Delay de 0.5 segundos
	system("cls"); // Limpa a Tela
	INICIO:
	printf("\n*** %s, Comece sua aventura escolhendo um dos equipamentos iniciais abaixo: ***\n\n- A: Espada de ferro (+10 ATK) + Escudo de madeira (+5 DEF)\n- B: Espada de Madeira (+5 ATK) + Escudo de Ferro (+15 DEF)\n- C: Lanca de ferro (+15 ATK)\n\n> ",user.nome);
	scanf(" %c",&inicial);
	fflush(stdin);
	Sleep(500);
	system("cls");
	switch (inicial)
	{
		case 'A':
		case 'a':
		user.ataque = user.ataque+10;
		user.defesa = user.defesa+5;
    	strcpy(user.arma,"Espada de Ferro (+10 ATK)");
    	strcpy(user.escudo,"Escudo de Madeira (+5 DEF)");
    	printf("Voce escolheu a Arma: %s\nVoce escolheu o Escudo: %s\n",user.arma,user.escudo);
    	break;

    	case 'B':
    	case 'b':
    	user.ataque = user.ataque+5;
    	user.defesa = user.defesa+15;
    	strcpy(user.arma,"Espada de Madeira (+5 ATK)");
    	strcpy(user.escudo,"Escudo de Ferro (+15 DEF)");
    	printf("Voce escolheu a Arma: %s\nVoce escolheu o Escudo: %s\n",user.arma,user.escudo);
		break;

		case 'C':
		case 'c':
		user.ataque = user.ataque+15;
		user.defesa = user.defesa+0;
		strcpy(user.arma,"Lanca de Ferro (+15 ATK)");
		strcpy(user.escudo,"Nenhum");
    	printf("Voce escolheu a Arma: %s\nVoce escolheu o Escudo: %s\n",user.arma,user.escudo);
    	break;

    	default:
    	printf("\nComando invalido. Escolha uma das opcoes abaixo:\n");
		goto INICIO;
	}
	printf("\nDigite qualquer tecla para continuar.\n\n> ");
	getch();
	fflush(stdin);
	Sleep(250);
	system("cls");
COMANDOS:
    Sleep(1000);
    system("cls");
    printf("\n*** Cidade de Noobvile ***\n");
    printf("\n*** Comandos: ***\n- A: Ver stats\n- B: Ver equipamento\n- C: Checar a loja da cidade\n- D: Se aventurar\n\n> ");
	scanf(" %c",&comando1); // Input de comando pro menu acima
	fflush(stdin); 
	Sleep(500);
	switch (comando1)
	{
		case 'A':
		case 'a':
		    printf("\n*** STATS ***\nATK: %d\nDEF: %d\nHP: %d\nGOLD: %d\n\n*************\n",user.ataque,user.defesa,user.hp,user.moedas);
		    printf("\nDigite qualquer tecla para retornar.\n\n> ");
        	getch();
        	fflush(stdin);
        	printf("\n");
	    	goto COMANDOS;
	    break;

	    case 'B':
	    case 'b':
	        printf("\nArma: %s\n",user.arma);
	     	printf("\nEscudo: %s\n",user.escudo);
	    	printf("\nDigite qualquer tecla para retornar.\n\n> ");
        	getch();
        	Sleep(250);
        	system("cls");
	    	goto COMANDOS;
		break;
		
	    case 'C':
	    case 'c':
FERREIRO: /*  Loja do Ferreiro da Cidade principal, acessado via 'D' em COMANDOS: */
        Sleep(500);
		system("cls");
        printf("\n*** Loja do Ferreiro Local ***\nSuas moedas: %d\n\n\nA: Espada de aco (+15 ATK) por 7 moedas.\n\nB: Escudo de Madeira (+5 DEF) por 2 moedas.\n\nC: Pocao de HP (Cura 5 HP ao comprar) 3 moedas.\nSeu HP: %d\n\nX: Sair\n\n> ",user.moedas,user.hp);
	    scanf(" %c",&loja1);
	    fflush(stdin);
	    Sleep(500);
	    switch (loja1)
	    {
	    case 'A':
	    case 'a':
	        Sleep(500);
	        system("cls");
	        if (user.moedas >= 7)
	        {
	    user.moedas = user.moedas - 7;
		printf("\nVoce comprou uma Espada de Aco e a equipou. Enquanto isso roubaram sua espada antiga. Oh nao!\n\nSuas moedas: %d",user.moedas);
		strcpy(user.arma,"Espada de Aco");
		user.ataque = 2 + 15;
		printf("\nSeu ataque atual agora vai ser de: %d\n",user.ataque);
		printf("\nDigite qualquer tecla para continuar.\n\n> ");
	    getch();
    	fflush(stdin);
		goto FERREIRO;
	    	}
	    	else
		    {
			printf("\nFerreiro: Voce nao tem moedas suficiente para isso! Vaza daqui!\n*Voce foi expulso do ferreiro*\n");
			printf("\nDigite qualquer tecla para continuar.\n\n> ");
	        getch();
			goto COMANDOS;
	    	}
		break;
		
		case 'B':
		case 'b':
	    	Sleep(500);
	    	system("cls");
		    if (user.moedas >=2)
	     	{
			Sleep(500);
			system("cls");
			user.moedas = user.moedas - 2;
			printf("\nVoce comprou um Escudo de Madeira e o equipou. Enquanto isso roubaram seu escudo antigo. Oh nao!\n\nSuas moedas: %d\n",user.moedas);
			strcpy(user.escudo,"Escudo de Madeira");
			user.defesa = 1 + 5;
			printf("\nSua defesa atual agora vai ser de: %d\n",user.defesa);
			printf("\nDigite qualquer tecla para continuar.\n\n> ");
	        getch();
		    goto FERREIRO;
	    	}
	    	else
	     	{
		printf("\nFerreiro: Voce nao tem moedas suficiente para isso! Vaza daqui!\n*Voce foi expulso do ferreiro*\n\nDigite qualquer tecla para voltar.\n\n> ");
		getch();
		goto COMANDOS;
		}
		break;
		
        case 'C':
        case 'c':
            if (user.moedas >=3)
            {
        	Sleep(500);
        	system("cls");
        	switch (user.hp)
        	{
        		case 1:
        	    	user.hp = 6;
        		break;
        	    case 2:
        	    	user.hp = 7;
        		break;
        		case 3:
        	    	user.hp = 8;
        		break;
        		case 4:
        	    	user.hp = 9;
        		break;
        		case 10:
        	    	printf("\nVoce ja esta com o HP maximo! (10)\n\nDigite qualquer tecla para voltar.\n\n> ");
        	    	getch();
        	    	Sleep(250);
        	    	goto FERREIRO;
        		break;
        		default:
        	    	user.hp = 10;
			}
        	user.moedas = user.moedas - 3;
        	printf("\nVoce comprou e tomou uma pocao de HP.\nHP: %d\n\nSuas moedas: %d\n\nDigite qualquer tecla para voltar.\n\n> ",user.hp,user.moedas);
        	getch();
        	goto FERREIRO;
	     	}
	    	else
	     	{
			printf("\nFerreiro: Voce nao tem moedas suficiente para isso! Vaza daqui!\n*Voce foi expulso do ferreiro*\n\nDigite qualquer tecla para voltar.\n\n> ");
			getch();
	        goto COMANDOS;
	    	}
		break;
		
		case 'X':
		case 'x':
	    	Sleep(500);
	    	system("cls");
		    goto COMANDOS;
	    	break;
	    	default: printf("\nComando invalido. Escolha uma das opcoes abaixo.\n"); /* Caso o usuario nao selecione nenhuma coisa pra comprar nem X para sair. */
	    	printf("\nDigite qualquer tecla para voltar.\n\n> ");
	        getch();
	    	goto FERREIRO;
		}
            case 'D':
            case 'd':
            encontro1 = rand() % 7; /* Sorteia um numero entre 0 e 2 - Caso 0: Nao encontra nada e volta para COMANDOS // Caso 1: Goblin // Caso 2: Aranha gigante // */
            // printf("%d",encontro1); - Mostra na tela o numero do sorteio, usado para testes
            switch (encontro1)
			{
			case 1:
			case 3:
            Sleep(500);
		    system("cls");
        		printf("\n*Andando pela floresta voce encontrou %s!*",goblin.nome);
        		/* Aqui começa a luta com o goblin na floresta */
COMBATEG1:
                Sleep(500);
                printf("\n\n---- Combate com %s ----\nAtaque %s: %d\nDefesa %s: %d\nHP %s: %d\n",goblin.nome,goblin.nome,goblin.ataque,goblin.nome,goblin.defesa,goblin.nome,goblin.hp); // Status Npc
                printf("\nAtaque %s: %d\nDefesa %s: %d\nHP %s: %d\n",user.nome,user.ataque,user.nome,user.defesa,user.nome,user.hp); // Status User
                printf("\nA: Atacar\n\nB: Fugir\n\n> ");
        		scanf(" %c",&resposta1);
        		fflush(stdin);
        		Sleep(500);
        		system("cls");
        		switch (resposta1) // Caso A: combate continua  // Caso B: Usuario tenta fugir (2/3 de chance de dar certo, 1/3 de chance de dar errado e tomar 1 hit e continuar o combate)
        		{
        		    case 'A':
        		    case 'a':
COMBATE1:               
                                                // Calculo do hit do Usuario
                        if (goblin.defesa <= 0)
                        {
                        	user.hit = rand() % user.ataque + 2;
						}
						else
					    {
					    	user.hit = rand() % user.ataque - (goblin.defesa/5) + 1;
						}
						// Calculo do hit do NPC
                        if (user.defesa <= 0)
                        {
                        	goblin.hit = rand() % goblin.ataque + 2;
						}
						else
						{
							goblin.hit = rand() % goblin.ataque - (user.defesa/5) + 1;
						}
						
						if (goblin.hit <= 0)
						{
							goblin.hit = 0;
						}
						user.hp = user.hp - goblin.hit; // Hp do usuario
						goblin.hp = goblin.hp - user.hit; // Hp do npc
						if (user.hp < 0)
						{
							user.hp = 0;
						}
						else 
						{
							user.hp = user.hp;
						}
						if (goblin.hp < 0)
						{
							goblin.hp = 0;
						}
						else
						{
							goblin.hp = goblin.hp;
						}
						printf("\n*%s ataca e da %d de dano.*\n*%s ataca e da %d de dano.*\n\nHP de %s: %d\nHP de %s: %d\n\n",user.nome,user.hit,goblin.nome,goblin.hit,user.nome,user.hp,goblin.nome,goblin.hp);
						Sleep(500);
                        if (user.hp <= 0 && goblin.hp <= 0)
						{
							printf("\n\nVoce matou o %s! -- Mas espere... Oh ceus, %s morreu!\n\n*************************\n\n GAME OVER\n\n*************************",goblin.nome,user.nome);
							printf("\nDigite qualquer tecla para reiniciar o Jogo.\n");
							getch();
							Sleep(500);
							system("cls");
							//goto START;
						}
						else if  (user.hp > 0 && goblin.hp > 0)
						{
							printf("\n\nDigite Y para atacar novamente ou outra tecla para Fugir.\n\n> ");
							scanf(" %c",&res2);
							Sleep(500);
                            system("cls");
                        switch (res2)
                        {
                        	case 'Y':
                        	case 'y':
                        	goto COMBATE1;
                        	break;
                        	
                        	default:
                        	user.moedas = user.moedas -1;
                        	printf("Voce fugiu com sucesso para cidade, mas perdeu 1 moeda no caminho!\n\nMoedas: %d\n\n",user.moedas);
                        	goto COMANDOS;
						}
						}
						else if (user.hp > 0 && goblin.hp <= 0)
						{
							goblin.loot = rand() % goblin.loot;
							user.moedas = user.moedas + goblin.loot;
							printf("\n\nParabens, voce matou %s!\n\nHP de %s: %d\n\n*Recompensa: %d moeda(s).*\n\nMoedas: %d\n\n",goblin.nome,user.nome,user.hp,goblin.loot,user.moedas);
							printf("Digite qualquer tecla para continuar.\n\n> ");
        			    	getch();
							goto COMANDOS;
						}
						else if (user.hp <= 0 && goblin.hp > 0)
						{
							printf("\n\nOh ceus, %s morreu!\n\n*************************\n\n GAME OVER\n\n*************************",user.nome);
							printf("\nDigite qualquer tecla para reiniciar o Jogo.\n");
							getch();
							Sleep(500);
							system("cls");
							//goto START;
						}
						break;
					case 'B':
        			case 'b':
        			Sleep(500);
		            system("cls");
		            int fugir1;
        			fugir1 = rand() % 2; /* Seleciona um numero aleatorio entre 0 e 2 - caso 0/2 voce nao consegue fugir e toma 1 hit do npc - caso 1 voce foge e volta para COMANDOS: */
        			switch (fugir1)
        			{
        				case 2:
        				Sleep(500);
	                	system("cls");
        				printf("\n*Voce conseguiu fugir com sucesso e voltou para a cidade!*");
        				printf("\nDigite qualquer tecla para continuar.\n\n> ");
        				getch();
        				goto COMANDOS;
        				break;

					    case 1:
					    Sleep(500);
	                	system("cls");
	                	goblin.hit = rand() % goblin.ataque/user.defesa + 2;
						printf("\n*Voce nao conseguiu fugir! %s te deu %d de dano.",goblin.nome,goblin.hit);
						user.hp = user.hp - goblin.hit;
						if (user.hp <= 0)
						{
							printf("\n\nOh ceus, %s morreu!\n\n*************************\n\n GAME OVER\n\n*************************",user.nome);
							printf("\nDigite qualquer tecla para reiniciar o Jogo.\n");
							getch();
							Sleep(500);
							system("cls");
							//goto START;
						}
						else 
					    {
						printf("\nDigite qualquer tecla para continuar.\n\n> ");
        				getch();
        				Sleep(500);
        				system("cls");
						goto COMBATEG2;
				     	}
						break;

						case 0:
	                    Sleep(500);
	                	system("cls");
        				printf("\n*Voce conseguiu fugir com sucesso e voltou para a cidade!*");
        				printf("\nDigite qualquer tecla para continuar.\n\n> ");
        				getch();
        				goto COMANDOS;
        				break;
					}
					break;
					default:
					printf("\nComando invalido. escolha uma das opcoes abaixo.\n");
	                Sleep(500);
	                goto COMBATEG1;
			}
		break;
		case 0:
		case 4:
		Sleep(500);
		    system("cls");
        		printf("\n*Andando pela floresta voce encontrou %s!*",aranha.nome);
        		/* Aqui começa a luta com npc na floresta */
COMBATEG2:
                Sleep(500);
                printf("\n\n---- Combate com %s ----\nAtaque %s: %d\nDefesa %s: %d\nHP %s: %d\n",aranha.nome,aranha.nome,aranha.ataque,aranha.nome,aranha.defesa,aranha.nome,aranha.hp); // Status NPC
                printf("\nAtaque %s: %d\nDefesa %s: %d\nHP %s: %d\n",user.nome,user.ataque,user.nome,user.defesa,user.nome,user.hp); // Status User
                printf("\nA: Atacar\n\nB: Fugir\n\n> ");
        		scanf(" %c",&resposta1);
        		fflush(stdin);
        		Sleep(500);
        		system("cls");
        		switch (resposta1)
        		{
        		    case 'A':
        		    case 'a':
COMBATE2:            
                        // Calculo do hit do Usuario
                        if (aranha.defesa <= 0)
                        {
                        	user.hit = rand() % user.ataque + 2;
						}
						else
					    {
					    	user.hit = rand() % user.ataque - (aranha.defesa/5) + 1;
						}
						// Calculo do hit do NPC
                        if (user.defesa <= 0)
                        {
                        	aranha.hit = rand() % aranha.ataque + 2;
						}
						else
						{
							aranha.hit = rand() % aranha.ataque - (user.defesa/5) + 1;
						}
						
						if (aranha.hit <= 0)
						{
							aranha.hit = 0;
						}
						user.hp = user.hp - aranha.hit; // Hp do usuario
						aranha.hp = aranha.hp - user.hit; // Hp do npc
						if (user.hp < 0)
						{
							user.hp = 0;
						}
						else 
						{
							user.hp = user.hp;
						}
						if (aranha.hp < 0)
						{
							aranha.hp = 0;
						}
						else
						{
							aranha.hp = aranha.hp;
						}
						printf("\n*%s ataca e da %d de dano.*\n*%s ataca e da %d de dano.*\n\nHP de %s: %d\nHP de %s: %d\n\n",user.nome,user.hit,aranha.nome,aranha.hit,user.nome,user.hp,aranha.nome,aranha.hp);
						Sleep(500);
                        if (user.hp <= 0 && aranha.hp <= 0)
						{
							printf("\n\nVoce matou %s! -- Mas espere... Oh ceus, %s morreu!\n\n*************************\n\n GAME OVER\n\n*************************",aranha.nome,user.nome);
							printf("\nDigite qualquer tecla para reiniciar o Jogo.\n");
							getch();
							Sleep(500);
							system("cls");
							//goto START;
						}
						else if  (user.hp > 0 && aranha.hp > 0)
						{
							printf("\n\nDigite Y para atacar novamente ou outra tecla para Fugir.\n\n> ");
							scanf(" %c",&res2);
							Sleep(500);
							system("cls");
                        switch (res2)
                        {
                        	case 'Y':
                        	case 'y':
                        	goto COMBATE2;
                        	break;
                        	
                        	default:
                        	user.moedas = user.moedas -1;
                        	printf("Voce fugiu com sucesso para cidade, mas perdeu 1 moeda no caminho!\n\nMoedas: %d\n\n",user.moedas);
                        	goto COMANDOS;
						}
						}
						else if (user.hp > 0 && aranha.hp <= 0)
						{
							aranha.loot = rand() % aranha.loot;
							user.moedas = user.moedas + aranha.loot;
							printf("\n\nParabens, voce matou %s!\n\nHP de %s: %d\n\n*Recompensa: %d moeda(s).*\n\nMoedas: %d\n\n",aranha.nome,user.nome,user.hp,aranha.loot,user.moedas);
							printf("Digite qualquer tecla para continuar.\n\n> ");
        			    	getch();
							goto COMANDOS;
						}
						else if (user.hp <= 0 && aranha.hp > 0)
						{
							printf("\n\nOh ceus, %s morreu!\n\n*************************\n\n GAME OVER\n\n*************************",user.nome);
							printf("\nDigite qualquer tecla para reiniciar o Jogo.\n");
							getch();
							Sleep(500);
							system("cls");
							//goto START;
						}
						break;
					case 'B':
        			case 'b':
        			Sleep(500);
		            system("cls");
		            int fugir1;
        			fugir1 = rand() % 2; /* Seleciona um numero aleatorio entre 0 e 2 - caso 0/2 voce nao consegue fugir e toma 1 hit do npc - caso 1 voce foge e volta para COMANDOS: */
        			switch (fugir1)
        			{
        				case 2:
        				Sleep(500);
	                	system("cls");
        				printf("\n*Voce conseguiu fugir com sucesso e voltou para a cidade!*");
        				printf("\nDigite qualquer tecla para continuar.\n\n> ");
        				getch();
        				goto COMANDOS;
        				break;

					    case 1:
					    Sleep(500);
	                	system("cls");
	                	aranha.hit = rand() % aranha.ataque/user.defesa + 2;
						printf("\n*Voce nao conseguiu fugir! %s te deu %d de dano.",aranha.nome,aranha.hit);
						user.hp = user.hp - aranha.hit;
						if (user.hp <= 0)
						{
							printf("\n\nOh ceus, %s morreu!\n\n*************************\n\n GAME OVER\n\n*************************",user.nome);
							printf("\nDigite qualquer tecla para reiniciar o Jogo.\n");
							getch();
							Sleep(500);
							system("cls");
							//goto START;
						}
						else 
				     	{
						printf("\nDigite qualquer tecla para continuar.\n\n> ");
        				getch();
        				Sleep(500);
        				system("cls");
						goto COMBATEG2;
				    	}
						break;

						case 0:
	                    Sleep(500);
	                	system("cls");
        				printf("\n*Voce conseguiu fugir com sucesso e voltou para a cidade!*");
        				printf("\nDigite qualquer tecla para continuar.\n\n> ");
        				getch();
        				goto COMANDOS;
        				break;
					}
					break;
					default:
					printf("\nComando invalido. escolha uma das opcoes abaixo.\n");
	                Sleep(500);
	                goto COMBATEG2;
			}
		break;
		case 5:
		system("cls");
COMBATEG3:
                Sleep(500);
                printf("\n\n---- Combate com %s ----\nAtaque %s: %d\nDefesa %s: %d\nHP %s: %d\n",esqueleto.nome,esqueleto.nome,esqueleto.ataque,esqueleto.nome,esqueleto.defesa,esqueleto.nome,esqueleto.hp); // Status Npc
                printf("\nAtaque %s: %d\nDefesa %s: %d\nHP %s: %d\n",user.nome,user.ataque,user.nome,user.defesa,user.nome,user.hp); // Status User
                printf("\nA: Atacar\n\nB: Fugir\n\n> ");
        		scanf(" %c",&resposta1);
        		fflush(stdin);
        		Sleep(500);
        		system("cls");
        		switch (resposta1) // Caso A: combate continua  // Caso B: Usuario tenta fugir (2/3 de chance de dar certo, 1/3 de chance de dar errado e tomar 1 hit e continuar o combate)
        		{
        		    case 'A':
        		    case 'a':
COMBATE3:                                       
                        // Calculo do hit do Usuario
                        if (esqueleto.defesa <= 0)
                        {
                        	user.hit = rand() % user.ataque + 2;
						}
						else
					    {
					    	user.hit = rand() % user.ataque - (esqueleto.defesa/5) + 1;
						}
						// Calculo do hit do NPC
                        if (user.defesa <= 0)
                        {
                        	esqueleto.hit = rand() % esqueleto.ataque + 2;
						}
						else
						{
							esqueleto.hit = rand() % esqueleto.ataque - (user.defesa/5) + 1;
						}
						
						if (esqueleto.hit <= 0)
						{
							esqueleto.hit = 0;
						}
						
						user.hp = user.hp - esqueleto.hit; // Hp do usuario
						esqueleto.hp = esqueleto.hp - user.hit; // Hp do esqueleto
						if (user.hp < 0)
						{
							user.hp = 0;
						}
						else 
						{
							user.hp = user.hp;
						}
						if (esqueleto.hp < 0)
						{
							esqueleto.hp = 0;
						}
						else
						{
							esqueleto.hp = esqueleto.hp;
						}
						printf("\n*%s ataca e da %d de dano.*\n*%s ataca e da %d de dano.*\n\nHP de %s: %d\nHP de %s: %d\n\n",user.nome,user.hit,esqueleto.nome,esqueleto.hit,user.nome,user.hp,esqueleto.nome,esqueleto.hp);
						Sleep(500);
                        if (user.hp <= 0 && esqueleto.hp <= 0)
						{
							printf("\n\nVoce matou o %s! -- Mas espere... Oh ceus, %s morreu!\n\n*************************\n\n GAME OVER\n\n*************************",esqueleto.nome,user.nome);
							printf("\nDigite qualquer tecla para reiniciar o Jogo.\n");
							getch();
							Sleep(500);
							system("cls");
							//goto START;
						}
						else if  (user.hp > 0 && esqueleto.hp > 0)
						{
							printf("\n\nDigite Y para atacar novamente ou outra tecla para Fugir.\n\n> ");
							scanf(" %c",&res2);
							Sleep(500);
                            system("cls");
                        switch (res2)
                        {
                        	case 'Y':
                        	case 'y':
                        	goto COMBATE3;
                        	break;
                        	
                        	default:
                        	user.moedas = user.moedas -1;
                        	printf("Voce fugiu com sucesso para cidade, mas perdeu 1 moeda no caminho!\n\nMoedas: %d\n\n",user.moedas);
                        	goto COMANDOS;
						}
						}
						else if (user.hp > 0 && esqueleto.hp <= 0)
						{
							esqueleto.loot = rand() % esqueleto.loot;
							esqueleto.lootraro = rand() % esqueleto.lootraro;
							user.moedas = user.moedas + esqueleto.loot;
							printf("\n\nParabens, voce matou %s!\n\nHP de %s: %d\n\n*Recompensa: %d moeda(s).*\n\nMoedas: %d\n\n",esqueleto.nome,user.nome,user.hp,esqueleto.loot,user.moedas);
							switch (esqueleto.lootraro)
							{
								case 4:
								user.ataque = user.ataque + 5;
								printf("\nAo matar o esqueleto voce encontra com ele um Livro antigo! Apos ler voce se sente mais forte. (+5 ATK)\n\nAtaque de %s: %d",user.nome,user.ataque);
							}
							printf("Digite qualquer tecla para continuar.\n\n> ");
        			    	getch();
							goto COMANDOS;
						}
						else if (user.hp <= 0 && esqueleto.hp > 0)
						{
							printf("\n\nOh ceus, %s morreu!\n\n*************************\n\n GAME OVER\n\n*************************",user.nome);
							printf("\nDigite qualquer tecla para reiniciar o Jogo.\n");
							getch();
							Sleep(500);
							system("cls");
							//goto START;
						}
						break;
					case 'B':
        			case 'b':
        			Sleep(500);
		            system("cls");
		            int fugir1;
        			fugir1 = rand() % 2; /* Seleciona um numero aleatorio entre 0 e 2 - caso 0/2 voce nao consegue fugir e toma 1 hit do npc - caso 1 voce foge e volta para COMANDOS: */
        			switch (fugir1)
        			{
        				case 2:
        				Sleep(500);
	                	system("cls");
        				printf("\n*Voce conseguiu fugir com sucesso e voltou para a cidade!*");
        				printf("\nDigite qualquer tecla para continuar.\n\n> ");
        				getch();
        				goto COMANDOS;
        				break;

					    case 1:
					    Sleep(500);
	                	system("cls");
	                	esqueleto.hit = rand() % esqueleto.ataque/user.defesa + 2;
						printf("\n*Voce nao conseguiu fugir! %s te deu %d de dano.",esqueleto.nome,esqueleto.hit);
						user.hp = user.hp - esqueleto.hit;
						if (user.hp <= 0)
						{
							printf("\n\nOh ceus, %s morreu!\n\n*************************\n\n GAME OVER\n\n*************************",user.nome);
							printf("\nDigite qualquer tecla para reiniciar o Jogo.\n");
							getch();
							Sleep(500);
							system("cls");
                            //goto START;
						}
						else 
					    {
						printf("\nDigite qualquer tecla para continuar.\n\n> ");
        				getch();
        				Sleep(500);
        				system("cls");
						goto COMBATEG2;
				     	}
						break;

						case 0:
	                    Sleep(500);
	                	system("cls");
        				printf("\n*Voce conseguiu fugir com sucesso e voltou para a cidade!*");
        				printf("\nDigite qualquer tecla para continuar.\n\n> ");
        				getch();
        				goto COMANDOS;
        				break;
					}
					default:
					printf("\nComando invalido. escolha uma das opcoes abaixo.\n");
	                Sleep(500);
	                goto COMBATEG3;
			}
		break;
		
		default:
		system("cls");
		Sleep(500);
		printf("\n*Depois de muito explorar voce encontra civilizacao.*");
		Sleep(500);
		printf("\n*Analisando os arredores voce chega a conclusao que esta tal civilizacao era a mesma da onde voce saiu.*");
		Sleep(500);
		printf("\n*Voce estava andando em circulos faz 30 Minutos. Ops*\n");
		Sleep(500);
		printf("\nDigite qualquer tecla para continuar.\n\n> ");
		getch();
		goto COMANDOS;
		}
     default:
	 system("cls");
	 printf("\nComando invalido. escolha uma das opcoes abaixo.\n");
	 Sleep(500);
	 goto COMANDOS;
}
}
