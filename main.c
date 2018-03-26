#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int main(int argc, char *argv[]) {
	srand(time(NULL));

	int moedas,hp,defesa,ataque,npc1,npc1atk,npc1def,npc1hp,loot1,res2;
	char user[50],inicial,arma,escudo,comando1,loja1,resposta1;

	/*
	Espada de Madeira = 1 // +5 ATK
	Espada de Ferro = 2 // + 10 ATK
	Espada de Aco = 3 // + 15 ATK
	Espada de Adamantio = 4 // +20 ATK

	Escudo de Madeira = 1 // +5 DEF
	Escudo de Ferro = 2 // + 15 DEF
	Escudo de Aco = 3 // + 22 DEF
	Escudo de Adamantio = 4 // + 31 DEF

	Lanca de Madeira = 11 // + 7 ATK
	Lanca de Ferro = 21 // + 20 ATK
	Lanca de Aco = 31 // + 25 ATK
	Lanca de Adamantio = 41 // + 35 ATK
	*/
	
	// Stats Iniciais
    ataque = 2;
	defesa = 1;
    hp = 10;
    moedas = 5;
    
	printf ("*** Bem vindo ao text-based RPG Sacred River ***\n\n"); // Mensagem inicial
	printf("Qual o seu nome?\n\n> ");
	scanf("%s",&user); // Pede input do usuário e armazena em 'user'
	fflush(stdin);
	Sleep(500); // Delay de 0.5 segundos
	system("cls"); // Limpa a Tela
INICIO:	printf("\n*** %s, Comece sua aventura escolhendo um dos equipamentos iniciais abaixo: ***\n\n- A: Espada de ferro (+10 ATK) + Escudo de madeira (+5 DEF)\n- B: Espada de Madeira (+5 ATK) + Escudo de Ferro (+15 DEF)\n- C: Lanca de ferro (+15 ATK)\n\n> ",user);
	scanf(" %c",&inicial);
	fflush(stdin);
	Sleep(500);
	system("cls");
	switch (inicial)
	{
		case 'A':
		case 'a':
		ataque = ataque + 10;
    	defesa = defesa + 5;
    	arma = 2;
    	escudo = 1;
    	printf("Voce escolheu a Arma: Espada de Ferro\nVoce escolheu o Escudo: Escudo de Madeira\n");
    	break;

    	case 'B':
    	case 'b':
    	ataque = ataque + 5;
	    defesa = defesa + 15;
	    arma = 1;
	    escudo = 2;
    	printf("Voce escolheu a Arma: Espada de Madeira\nVoce escolheu o Escudo: Escudo de Ferro\n");
		break;

		case 'C':
		case 'c':
		ataque = ataque + 15;
		defesa = defesa + 0;
		arma = 21;
		escudo = 0;
    	printf("Voce escolheu a Arma: Lanca de Ferro\nVoce escolheu o Escudo: Nenhum\n");
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
    printf("\n*** Comandos: ***\n- A: Ver stats\n- B: Ver equipamento\n- C: Checar a loja da cidade\n- D: Se aventurar\n\n> ");

	scanf(" %c",&comando1); // Input de comando pro menu acima
	fflush(stdin); 
	Sleep(500);
	switch (comando1)
	{
		case 'A':
		case 'a':
		printf("\n*** STATS ***\nATK: %d\nDEF: %d\nHP: %d\nGOLD: %d\n\n*******\n",ataque,defesa,hp,moedas);
		printf("\nDigite qualquer tecla para retornar.\n\n> ");
     	getch();
     	fflush(stdin);
     	printf("\n");
		goto COMANDOS;
	    break;

	    case 'B':
	    case 'b':
	    	switch (arma) // Info sobre Arma
	    	{
	    		case 1:
	    		printf("\nArma: Espada de Madeira. (+5 ATK)\n");
	    		break;

	    		case 2:
	    		printf("\nArma: Espada de Ferro. (+10 ATK)\n");
	    		break;

	    		case 3:
	    		printf("\nArma: Espada de Aco. (+15 ATK)\n");
	    		break;

	    		case 11:
	    		printf("\nArma: Lanca de Madeira. (+10 ATK)\n");
	    		break;

	    		case 21:
	    		printf("\nArma: Lanca de Ferro. (+15 ATK)\n");
				break;

	    		case 31:
	    		printf("\nArma: Lanca de aco. (+20 ATK)\n");
			    break;
			}
			switch (escudo) // Info sobre Escudo
			{
				case 1:
				printf("\nEscudo: Escudo de Madeira. (+5 DEF)\n");
				break;

				case 2:
				printf("\nEscudo: Escudo de Ferro (+15 DEF)\n");
				break;

				case 3:
				printf("\nEscudo: Escudo de Aco (+22 DEF)\n");
			    break;
			}
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
        printf("\n*** Loja do Ferreiro Local ***\nSuas moedas: %d\n\nA: Espada de aco (+15 ATK) por 7 moedas.\nB: Escudo de Madeira (+5 DEF) por 2 moedas.\nC: Pocao de HP (Cura 5 HP ao comprar) 3 moedas.\nSeu HP: %d\n\nX: Sair\n\n> ",moedas,hp);
	    scanf(" %c",&loja1);
	    fflush(stdin);
	    Sleep(500);
	    switch (loja1)
	    {
	    case 'A':
	    case 'a':
	    Sleep(500);
	    system("cls");
	    if (moedas >=7)
	    {
	    moedas = moedas - 7;
		printf("\nVoce comprou uma Espada de aco e a equipou. Enquanto isso roubaram sua espada antiga. Oh nao!\n\nSuas moedas: %d",moedas);
		arma = 3;
		ataque = 2 + ataque;
		printf("\nSeu ataque atual agora vai ser de: %d\n",ataque);
		goto FERREIRO;
		}
		else
		{
			printf("\nFerreiro: Voce nao tem moedas suficiente para isso! Vaza daqui!\n*Voce foi expulso do ferreiro*\n");
			goto COMANDOS;
		}
		break;
		case 'B':
		case 'b':
		Sleep(500);
		system("cls");
		if (moedas >=2)
		{
			Sleep(500);
			system("cls");
			moedas = moedas -2;
			printf("\nVoce comprou um Escudo de Madeira e o equipou. Enquanto isso roubaram seu escudo antigo. Oh nao!\n\nSuas moedas: %d\n\nVoltando para o Ferreiro...",moedas);
			escudo = 1;
			defesa = 5+1;
			printf("\nSua defesa atual agora vai ser de: %d\n",defesa);
			Sleep(2000);
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
        if (moedas >=3)
        {
        	Sleep(500);
        	system("cls");
        	switch (hp)
        	{
        		case 1:
        		hp = 6;
        		break;
        		case 2:
        		hp = 7;
        		break;
        		case 3:
        		hp = 8;
        		break;
        		case 4:
        		hp = 9;
        		break;
        		case 10:
        		printf("\nVoce ja esta com o HP maximo! (10)\n\nDigite qualquer tecla para voltar.\n\n> ");
        		getch();
        		Sleep(250);
        		goto FERREIRO;
        		break;
        		default:
        		hp = 10;
        		break;
			}
        	moedas = moedas-3;
        	printf("\nVoce comprou e tomou uma pocao de HP.\nHP: %d\n\nSuas moedas: %d\n\nDigite qualquer tecla para voltar.\n\n> ",hp,moedas);
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
		Sleep(500);
		goto FERREIRO;
		break;
		}
            case 'D':
            case 'd':
            Sleep(500);
		   system("cls");
{
        	Sleep(500);
		    system("cls");
        	npc1atk = 3;
        	npc1def = 0;
        	npc1hp = 7;
        	int npc1hit1;
        	int fugir1;
        	int userhit1;
        		printf("\n*Andando pela floresta voce encontrou um Goblin!*");
        		/* Aqui começa a luta com o goblin na floresta */
COMBATEG1:
                Sleep(500);
                printf("\n\n---- Combate com Goblin ----\nAtaque: %d\nDefesa: %d\nHP: %d\n\nA: Atacar\n\nB: Fugir\n\n> ",npc1atk,npc1def,npc1hp);
        		scanf(" %c",&resposta1);
        		fflush(stdin); // sla oq faz mas impede de 'resposta1' ser usado pra outros 'scanf' seguidos
        		Sleep(500);
        		system("cls");
        		switch (resposta1)
        		{
        		    case 'A':
        		    case 'a':
COMBATE1:               userhit1 = rand() % ataque; /* Aqui comeca os ataques do Goblin */
						npc1hit1 = rand() % npc1atk/defesa +2; /* Calculo do hit, que diminue um pouco de acordo com defesa */
						hp = hp - npc1hit1;
						npc1hp = npc1hp - userhit1;
						printf("\n*Goblin ataca e da %d de dano.*\n*%s ataca e da %d de dano.*\n\nHP de %s: %d\nHP de Goblin: %d\n\n",npc1hit1,user,userhit1,user,hp,npc1hp);
						Sleep(500);
                        if (hp <= 0 && npc1hp <= 0)
						{
							printf("\n\nVoce matou o Goblin! -- Mas espere... Oh ceus, %s morreu!\n\n*************************\n\n GAME OVER\n\n*************************",user);
							printf("\nDigite qualquer tecla para finalizar.\n\n> ");
        			     	getch();
                        	return 0;
						}
						else if  (hp > 0 && npc1hp > 0)
						{
							printf("\n\nDigite Y para atacar novamente ou outra tecla para Fugir.\n\n> ");
							scanf(" %c",&res2);
                        switch (res2)
                        {
                        	case 'Y':
                        	case 'y':
                        	goto COMBATE1;
                        	break;

                        	default:
                        	moedas = moedas -1;
                        	printf("Voce fugiu com sucesso para cidade, mas perdeu 1 moeda no caminho!\n\nMoedas: %d\n\n",moedas);
                        	goto COMANDOS;
						}
						}
						else if (hp > 0 && npc1hp <= 0)
						{
							loot1 = rand() % 3;
							moedas = moedas + loot1;
							printf("\n\nParabens, voce matou o Goblin!\n\nHP de %s: %d\n\n*Recompensa: %d moeda(s).*\n\nMoedas: %d\n\n",user,hp,loot1,moedas);
							printf("Digite qualquer tecla para continuar.\n\n> ");
        			    	getch();
							goto COMANDOS;
						}
						else if (hp <= 0 && npc1hp > 0)
						{
							printf("\n\nOh ceus, %s morreu!\n\n*************************\n\n GAME OVER\n\n*************************",user);
							return 0;
						}
						break;
					case 'B':
        			case 'b':
        			Sleep(500);
		            system("cls");
        			fugir1 = rand() % 2; /* Seleciona um numero aleatorio entre 0 e 2 - caso 0/2 voce nao consegue fugir e toma 1 hit do goblin - caso 1 voce foge e volta para COMANDOS: */
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
						printf("\n*Voce nao conseguiu fugir! O Goblin te deu %d de dano.",npc1hit1);
						hp = hp - npc1hit1;
						goto COMBATEG1;
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
			}
	    }
     default:
	 system("cls");
	 printf("\nComando invalido. escolha uma das opcoes abaixo.\n");
	 Sleep(500);
	 goto COMANDOS;
	 break;
}
}

