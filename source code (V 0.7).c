#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	srand(time(NULL));
	
	char user[50];
	int moedas,hp,defesa,ataque;
	char inicial;
	char arma;
	char escudo;
	char comando1;
	char loja1;
	int npc1;
	int npc1atk,npc1def,npc1hp;
    char resposta1;
    int loot1;
    int res2;
	
	/*
	Espada de Madeira = 1
	Espada de Ferro = 2
	Espada de Aco = 3
	Espada de Adamantio = 4
	u
	Escudo de Bronze = 1
	Escudo de Ferro = 2
	Escudo de Aco = 3
	Escudo de Adamantio = 4
	
	Lanca de Madeira = 11
	Lanca de Ferro = 21
	Lanca de Aco = 31
	Lanca de Adamantio = 41

	ATK inicial: 2
	DEF inicial: 0
	HP inicial: 10
	GOLD inicial: 5
	*/
	
	moedas = 5;
    hp = 10;
    defesa = 0;
    ataque = 2;
	
	printf ("*** Bem vindo ao text-based RPG *Sacred River* Qual o seu nome?***\n\n> ");
	scanf("%s",&user);
	
	/*
	Ataque da lanca de ferro: 20
	Ataque da espada de madeira: 5
	Defesa do escudo de ferro: 15
	Ataque da espada de ferro: 10
	*/
	
INICIO:	printf("\n*** %s, Comece sua aventura escolhendo um dos equipamentos iniciais abaixo: ***\n\n- A: Espada de ferro (+10 ATK) + Escudo de madeira (+5 DEF)\n- B: Espada de Madeira (+5 ATK) + Escudo de Ferro (+15 DEF)\n- C: Lanca de ferro (+20 ATK)\n\n> ",user);
	scanf(" %c",&inicial);
	
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
		ataque = ataque + 20;
		defesa = defesa + 0;
		arma = 21;
		escudo = 0;
    	printf("Voce escolheu a Arma: Lanca de Ferro\nVoce escolheu o Escudo: Nenhum\n");
    	break;
    	
    	default:
    	printf("\nComando invalido. Escolha uma das opcoes abaixo:\n");
		goto INICIO;
	}
COMANDOS:	
     
    printf("\n*** Comandos: ***\n- A: Ver stats\n- B: Ver equipamento\n- C: Checar a loja da cidade\n- D: Se aventurar\n\n> ");
	scanf(" %c",&comando1); // Input de comando pro menu acima
	
	switch (comando1)
	{
		case 'A':
		case 'a':
		printf("*** STATS ***\nATK: %d\nDEF: %d\nHP: %d\nGOLD: %d\n\n*******\n\n",ataque,defesa,hp,moedas);
     	
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
	    		printf("\nArma: Lanca de Madeira. (+7 ATK)\n");
	    		break;
	    		
	    		case 21:
	    		printf("\nArma: Lanca de Ferro. (+20 ATK)\n");	
				break;
				
	    		case 31:
	    		printf("\nArma: Lanca de aco. (+25 ATK)\n");		
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
		goto COMANDOS;
		break;
	    case 'C':
	    case 'c':
FERREIRO: /*  Loja do Ferreiro da Cidade principal, acessado via 'D' em COMANDOS: */
        printf("\n*** Loja do Ferreiro Local ***\nSuas moedas: %d\n\nA: Espada de aco (+15 ATK) por 7 moedas.\nB: Escudo de Madeira (+5 DEF) por 2 moedas.\n\nX: Sair\n\n> ",moedas);
	    scanf(" %c",&loja1);
	    switch (loja1)
	    {
	    case 'A':
	    case 'a':
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
		if (moedas >=2)
		{
			moedas = moedas -2;
			printf("\nVoce comprou um Escudo de Madeira e o equipou. Enquanto isso roubaram seu escudo antigo. Oh nao!\n\nSuas moedas: %d",moedas);
			escudo = 1;
			defesa = 5;
			printf("\nSua defesa atual agora vai ser de: %d\n",defesa);
		goto FERREIRO;
		}

		else
		{
		
		printf("\nFerreiro: Voce nao tem moedas suficiente para isso! Vaza daqui!\n*Voce foi expulso do ferreiro*\n");
		goto COMANDOS;
		}
		break;
		
		case 'X':
		case 'x':
		goto COMANDOS;
		break;
	}
			default : /* Caso o usuario nao selecione nenhuma coisa pra comprar nem X para sair. */
			printf("\nComando invalido. Escolha uma das opcoes abaixo.\n");
			
            case 'D':
            case 'd':
        	npc1 = rand() % 2; /* Seleciona um numero aleatorio entre 2 e 0, caso 1 voce encontra um goblin, caso 2/0 voce volta para a cidade (COMANDOS:)
			BUG: mesmo caindo em 0 e 2, o programa continua rodando pro primeiro 'if' e encontrando o goblin, e não segue pro else */
        	printf("\n%d\n",npc1);
        	if (npc1 = 1)
        	{
        	npc1atk = 3;
        	npc1def = 0;
        	npc1hp = 7;
        	int npc1hit1;
        	int fugir1;
        	int userhit1;
        	npc1hit1 = rand() % npc1atk;
        	
        		printf("\n*Andando pela floresta voce encontrou um Goblin!*");
        		/* Aqui começa a luta com o goblin na floresta */
COMBATEG1:		printf("\n\n---- Combate com Goblin ----\nAtaque: %d\nDefesa: %d\nHP: %d\n\nA: Atacar\n\nB: Fugir\n\n> ",npc1atk,npc1def,npc1hp);
        		scanf(" %d",&resposta1);
        		switch (resposta1)
        		{
        			case 'B':
        			case 'b':
        			fugir1 = rand() % 1; /* Seleciona um numero aleatorio entre 0 e 2 - caso 0/2 voce nao consegue fugir e toma 1 hit do goblin - caso 1 voce foge e volta para COMANDOS: */
        			if (fugir1 = 2)
        			{
        				
        				printf("\n*Voce conseguiu fugir com sucesso e voltou para a cidade!*");
        				goto COMANDOS;
					}
					else 
					{
					
						printf("\n*Voce nao conseguiu fugir! O Goblin te deu %d de dano.",npc1hit1);
						hp = hp - npc1hit1;
						goto COMBATEG1;
					}
					break;
        		    case 'A':
        		    case 'a':
COMBATE1:         	    userhit1 = rand() % ataque; /* Aqui comeca os ataques do Goblin */
						npc1hit1 = rand() % npc1atk - defesa;
						hp = hp - npc1hit1;
						npc1hp = npc1hp - userhit1;
						printf("\n*Goblin ataca e da %d de dano.*\n*%s ataca e da %d de dano.*\n\nHP de %s: %d\nHP de Goblin: %d\n\n",npc1hit1,user,userhit1,user,hp,npc1hp);
                        if (hp <= 0 && npc1hp <= 0)
						{
							printf("\n\nVoce matou o Goblin! -- Mas espere... Oh ceus, %s morreu!\n\n*************************\n\n GAME OVER\n\n*************************",user);
                        	return 0;
						}
						else if  (hp > 0 && npc1hp > 0)
						{
							printf("\n\nDigite Y para atacar novamente ou outra tecla para Fugir.\n\n> ");
							scanf(" %c",&res2);
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
							goto COMANDOS;
						}
						else if (hp <= 0 && npc1hp > 0)
						{
							printf("\n\nOh ceus, %s morreu!\n\n*************************\n\n GAME OVER\n\n*************************",user);
							return 0;
						}
						break;
						
						default: 
						printf("");
						goto COMBATE1;
				}
			}
			else 
			{
				printf("\n\n*Voce anda faz 30 Minutos e nao encontra nada. Voce acaba voltando para cidade.*\n\n");
				goto COMANDOS;
			}
        	
}

}

