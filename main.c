#include <raylib.h>
#include <stdio.h>
#include <math.h>

typedef struct 
{
    int altura;
    int base;
    int hipotenusa;
   //hipotenusa = sqrt(altura*altura + base*base);
}triangulo;
void movimentacao(Rectangle* Jorger)
{
        if (IsKeyDown(KEY_DOWN))
        {
            (Jorger->y)+= 4; //y cresce para baixo.
        }
        else if(IsKeyDown(KEY_UP))
        {
            (Jorger->y) -= 4;
        }
        else if(IsKeyDown(KEY_RIGHT))
        {
            (Jorger->x) +=4;
        }
        else if(IsKeyDown(KEY_LEFT))
        {
            (Jorger->x) -=4;
        }
            
    
}

void colisao(Rectangle* Jorger)
{ 
           if(IsKeyDown(KEY_LEFT))
           
           {
               (Jorger->x)+=4;
               
           }
           if(IsKeyDown(KEY_RIGHT))
           {
               (Jorger->x)-=4;
               
           }
           if(IsKeyDown(KEY_UP))
           {
               (Jorger->y)+=4;
           }
           if(IsKeyDown(KEY_DOWN))
           {
               (Jorger->y)-=4;
               
           } 
    
}


void tamanhotela(Rectangle* Jorger, int screenHeight,int screenWidth)
{
        if(Jorger->x+53>screenWidth)
        {
            Jorger->x = screenWidth-53;
        }
        else if(Jorger->x-8<0) 
        {
            Jorger->x=0+8;
        }
        else if(Jorger->y+52>screenHeight)
        {
            Jorger->y=screenHeight-52;
        }
        else if(Jorger->y-10<0)
        {
            Jorger->y=0+10;
        }
}


void desenharconflito(Texture2D fala)
{
     
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText("Conflito: Ir para a festa de Carla.\nAjude Jorge a deixar seus pensamentos mais funcionais",250,650,20,WHITE);
     DrawText(" Aperte A para: Ninguém me quer lá\nAperte B para: Vai ser divertido",220,700,20,WHITE);
     
}
void desenharconflito2(Texture2D fala)
{
     
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText("Conflito: Na festa, alguém te chamou para dançar.\n",250,650,20,WHITE);
     DrawText(" Aperte A para: Sim. Estou entre amigos, ninguém vai ligar\nAperte B para: Não. Vou passar vergonha",220,680,20,WHITE);
     
}
void desenharconflito3(Texture2D fala)
{
     
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText("Conflito: Alguém está olhando para você.\n",250,650,20,WHITE);
     DrawText(" Aperte A para: Talvez ela queira conversar\nAperte B para: A algo de errado comigo",220,680,20,WHITE);
     
}

void desenharconflito4(Texture2D fala)
{
     
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText("Conflito: Apresentar trabalho em público.\nAjude Jorge a deixar seus pensamentos mais funcionais",250,650,20,WHITE);
     DrawText(" Aperte A para: Todo mundo já esteve na mesma situação\nAperte B para: Todos vão estar me julgando",220,700,20,WHITE);
     
}
void desenharconflito5(Texture2D fala)
{
     
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText("Conflito: Um grupo de pessoas está rindo no fundo da sala.\n",250,650,20,WHITE);
     DrawText(" Aperte A para: Estão rindo de mim\nAperte B para: Eles conversam em todas as aulas",220,680,20,WHITE);
     
}
void desenharconflito6(Texture2D fala)
{
     
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText("Conflito: O professor está escrevendo algo em sua prancheta.\n",250,650,20,WHITE);
     DrawText(" Aperte A para: Ele só está tomando notas\nAperte B para: Eu estou falando tudo errado",220,680,20,WHITE);
     
}
void desenharconflito7(Texture2D fala)
{
     
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText("Conflito: Estar em um elevador cheio.\nAjude Jorge a deixar seus pensamentos mais funcionais",250,650,20,WHITE);
     DrawText(" Aperte A para: Vou ficar sem ar\nAperte B para: Vai dar tudo certo",220,700,20,WHITE);
     
}
void desenharconflito8(Texture2D fala)
{
     
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText("Conflito: O lugar está apertado.\n",250,650,20,WHITE);
     DrawText(" Aperte A para: Tem mais gente do que o elevador aguenta\nAperte B para: Só está um pouco cheio",220,680,20,WHITE);
     
}
void desenharconflito9(Texture2D fala)
{
     
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText("Conflito: Você está com medo de ficar preso",250,650,20,WHITE);
     DrawText(" Aperte A para: Fazer exercício de respiração\nAperte B para: Acho que vou morrer",220,700,20,WHITE);
     
}
void batalhafuncao(int* ruim,int opc, int* batalha)
{
   if(opc == 1)
   {
       if(IsKeyPressed(KEY_A)) //A=ruim, B=bom;
       {
           (*ruim)++;
           (*batalha)++;
       }
       else if(IsKeyPressed(KEY_B))
       {
           (*ruim)--;
           (*batalha)++;
       }
   }
   else if(opc == 2)
   {
       if(IsKeyPressed(KEY_A)) //A=bom, B=ruim;
       {
           (*ruim)--;
           (*batalha)++;
       }
       else if(IsKeyPressed(KEY_B))
       {
           (*ruim)++;
           (*batalha)++;
       }
       
   }
}

void batalhafuncao2(Texture2D fala,int* ruim, int* batalha)
{
      if((*batalha)==1)
      {
          desenharconflito(fala);
          batalhafuncao(&(*ruim),1,&(*batalha)); 
          
      }
      else if((*batalha)==2)
      {
          desenharconflito2(fala);
          batalhafuncao(&(*ruim),2,&(*batalha));
          
      }    
      else if((*batalha)==3)
      {
        desenharconflito3(fala);
        batalhafuncao(&(*ruim),2,&(*batalha));
      } 
      else if((*batalha)==4)
      {
        (*batalha)=0;
      }          
        
       
        
}
void batalhafuncao3(Texture2D fala,int* ruim, int* batalha)
{
      if((*batalha)==1)
      {
          desenharconflito4(fala);
          batalhafuncao(&(*ruim),2,&(*batalha)); 
          
      }
      else if((*batalha)==2)
      {
          desenharconflito5(fala);
          batalhafuncao(&(*ruim),1,&(*batalha));
          
      }    
      else if((*batalha)==3)
      {
        desenharconflito6(fala);
        batalhafuncao(&(*ruim),2,&(*batalha));
      } 
      else if((*batalha)==4)
      {
        (*batalha)=0;
      }              
        
}
void batalhafuncao4(Texture2D fala,int* ruim, int* batalha)
{
      if((*batalha)==1)
      {
          desenharconflito7(fala);
          batalhafuncao(&(*ruim),1,&(*batalha)); 
          
      }
      else if((*batalha)==2)
      {
          desenharconflito8(fala);
          batalhafuncao(&(*ruim),1,&(*batalha));
          
      }    
      else if((*batalha)==3)
      {
        desenharconflito9(fala);
        batalhafuncao(&(*ruim),2,&(*batalha));
      } 
      else if((*batalha)==4)
      {
        (*batalha)=0;
      }                
}

void atualizarestabilidade(int* stress,int* estabilidade)//mudar nome dessa função
{
    if((*stress)>= 10)
    {
        (*estabilidade) = *estabilidade-2;
        (*stress)=5;
    }
    if((*stress)<=0)
    {
        (*estabilidade) = *estabilidade+2;
        (*stress)=5;
    }
    
}
void diversaoaviso(Texture2D fala)//mudanças a serem feitas
{
     int contador = 0;
     contador++;
     int segundos = 0;
     if(contador%60 == 0){
         segundos++;
     }
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText(TextFormat("Está na hora de Jorge se divertir %i", segundos),370,700,20,WHITE);  
     

     
}
void terapiaaviso(Texture2D fala)
{
     
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText("Está na hora de Jorge ir para a terapia",350,700,20,WHITE);  
     
}

/*
Coisas dos outros personagens
//Image Karolim = LoadImage("/jogoip/Karol01.png");
//Image Guilhermeim = LoadImage("/jogoip/Guilherme01.png");
//ImageResize (&Karolim,144,104);
//ImageResize (&Guilhermeim,144,104);
//Texture2D Karoltx = LoadTextureFromImage(Karolim);
//Texture2D Guilhermetx = LoadTextureFromImage(Guilhermeim);
*/
void tudoDoJorge(){
    
    int screenWidth = 1366; //dimenssão da minha tela
    int screenHeight = 768;
    int contadordetempo = 0;
    
    //Carregando imagem e transformando em textura:
    //Image:
        Image Quarto = LoadImage("/jogoip/Quarto002.png"); //diretorio apartir do C: com as \ invertidas (/);
        Image Jorgeim = LoadImage("/jogoip/Jorge01.png");
        Image memoriasim = LoadImage("/jogoip/memorias.png");
        Image monstro = LoadImage("/jogoip/monstro2.png");
        Image fala = LoadImage("/jogoip/fala.png");
     //Image Resize:
        ImageResize (&Jorgeim,144,104); //144,104,(108,78) - Aumentando a imagem original
        ImageResize (&Quarto,1366,788); //passar o endereço pq ele modifica a imagem original.
        ImageResize (&fala,1366,300);
        ImageResize (&monstro,1300,678);
     //Texture2D:
        Texture2D Quartotx = LoadTextureFromImage(Quarto);
        Texture2D Jorgetx = LoadTextureFromImage(Jorgeim);
        Texture2D memoriastx = LoadTextureFromImage(memoriasim);
        Texture2D falatx = LoadTextureFromImage(fala);
        Texture2D monstrotx = LoadTextureFromImage(monstro); 
     //Rectengles:
        Rectangle Jorgerec = {0,0,53,102};// testando o tamanho do boneco no mapa (pegando só esse retângulo)
        //Rectangle Karolrec = {0,0,55,102}; // Esta ok
        //Rectangle Guilhermerec = {0,0,55,102}; //se desejar aumentar manter a proporção para os 3 bonecos (usar multiplo)
       //Retângulo de movimentação:
        Rectangle Jorger = {17,400,53,51}; //um retângulo de colisão que representa Jorge (metade da altura para colidir com o pé)
       //criando colisão
        Rectangle estante = {330,116,979,180}; //colisão para a estante
        Rectangle memoria1 = {500,325,20,3};
        Rectangle memoria2 = {600,325,20,3};
        Rectangle memoria3 = {600,525,20,5};
        Rectangle memoria4 = {965,340,20,3};
        Rectangle memoriasad1 = {800,600,20,5};
        Rectangle conflito = {930,300,70,80};
        Rectangle mesa = {525,405,305,100};
        Rectangle pe1= {570,515,20,15};
        Rectangle pe2= {790,515,20,15};
        Rectangle lixo = {1070,304,113,20};
        Rectangle parede1 = {0,0,190,340};
        Rectangle parede2 = {1166,0,190,340};
        Rectangle parede3 = {221,304,55,20};
        Rectangle parede4 = {0,669,190,340};
        Rectangle parede5 = {1166,669,190,340};
        Rectangle memoriasrec = {0,0,30,20}; //ok!
        Rectangle memoriassadrec = {30,20,30,20}; //ok!
        //Rectangle conflitorec = {60,40,35,20};//slah o compilador de um warning
        Rectangle monstrorec = {0,0,90,90};
       //posição das memórias:
        Vector2 memoriasp = {500,325}; //ferias com a família
        Vector2 memoriasp2 = {600,325}; //ganhou um ps4
        Vector2 memoriasp3 = {600,525}; //passou de ano
        Vector2 memoriaspsad1 = {800,600}; //perdeu contato com um amigo querido
        Vector2 memoriap4 = {965,340};
        Vector2 conflitop = {900,300};
    //variáveis :
    int memoria = 0;
    int stress = 5; //chegando a 0 aumenta estabilidade, chegando a 10 diminui.
    int estabilidade = 10; //chegando a 30 (exemplo) passa de nível, chegando a 0 perde
    int sad = 0; 
    int desafio = 0;
    int batalha = -1;
    int ruim = 0;
    int desenhar = 1;
    int diversao = 0;
    int terapia = 0;
    int desenharmemoria[6] = {1,1,1,1,1,1};
    int checkpoint = 0;
    checkpoint = qual_level(checkpoint);
    
    while (!WindowShouldClose())   
    {
        /*
        Coisas da Jarol e do Guilherme:
        //Vector2 Karolp = {circulo1.posicaox+100,circulo1.posicaoy+49};
        // Vector2 Guilhermep = {circulo1.posicaox+100,circulo1.posicaoy+49};
        
        */
         contadordetempo++;
         Vector2 Jorgep = {Jorger.x,Jorger.y-51}; //posição do Jorge (menos 51 para a colisão ficar no pé)
         //Posição do mouse na tela
         int x = GetMouseX();
         int y = GetMouseY();
        
        //função de movimentação do jorge:
         movimentacao(&Jorger);
        //Checando se saiu do mapa:
        tamanhotela(&Jorger,screenHeight,screenWidth);
        //atualizando estabilidade:
        atualizarestabilidade(&stress,&estabilidade);
        
        //checando colisão:
        if(CheckCollisionRecs(Jorger,estante)==1)
        {
            Jorger.y+=4;
            if(memoria==1 && IsKeyPressed(KEY_ENTER)==1)
            {
                if(sad==0)
                {
                    stress = stress-2;
                }
                else
                {
                    stress = stress+2;
                    sad=0;
                }
                
                memoria=0;
            }
        }
        else if(CheckCollisionRecs(Jorger,mesa)==1 ||CheckCollisionRecs(Jorger,pe1)==1|| CheckCollisionRecs(Jorger,pe2)==1)
        {
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,parede1)==1) 
        {
            colisao(&Jorger);
            if(diversao==1)
            {
                
                desenhar=0;
                stress = stress - 5;
                diversao=0;
            }
            
        }
        else if(CheckCollisionRecs(Jorger,parede2)==1)
        {
            colisao(&Jorger);
            if(terapia==1)
            {
                desenhar=0;
                estabilidade = estabilidade + 5;
                terapia=0;
            }
            
        }
        else if(CheckCollisionRecs(Jorger,parede3))
        {
            colisao(&Jorger); 
        }
        else if(CheckCollisionRecs(Jorger,parede4) || CheckCollisionRecs(Jorger,parede5))
        {
            colisao(&Jorger); 
        }
        else if(CheckCollisionRecs(Jorger,memoria1)==1)
        {
            if(IsKeyPressed(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[0]=0;
                 memoria=1;
                 memoria1.x=0;
                 memoria1.y=0;
            }
            
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoria2)==1)
        {
            if(IsKeyPressed(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[1]=0;
                 memoria=1;
                 memoria2.x=0;
                 memoria2.y=0;
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoria3))
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[2]=0;
                 memoria=1;
                 memoria3.x=0;
                 memoria3.y=0;
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoria4) && contadordetempo>=3600)
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[5]=0;
                 if(ruim>0)
                 {
                     memoria=1;
                     sad=1;
                     //criou um memória ruim:
                     stress = stress+3;
                     
                 }
                 else
                 {
                     memoria=1;
                     //recompensa por ter dado certo:
                     stress = stress-3;
                 }
                 
                 memoria4.x=0;
                 memoria4.y=0;
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,conflito)==1 && contadordetempo>=3600)
        {
            if(IsKeyDown(KEY_ENTER))
            {
                 
                 batalha=1;
                 desafio=1;
                 
                
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoriasad1))
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[3]=0;
                 memoria=1;
                 sad=1;
                 memoriasad1.x=0;
                 memoriasad1.y=0;
            }
            colisao(&Jorger);
        }
        else if (CheckCollisionRecs(Jorger,lixo))
        {
           if(IsKeyPressed(KEY_ENTER)==1 && memoria==1)
            {
                if(sad==1)
                {
                    stress--;
                    sad=0;
                }
                else
                {
                    stress = stress+3;
                }
                 memoria=0;
            }
            colisao(&Jorger); 
        }    
            int minutos = 3600;
            if(contadordetempo==2*minutos)
            {
                diversao=1;
                
            }
            if(contadordetempo==5*minutos)
            {
                terapia=1;
                
                //lembrar=1;
            }
            if(contadordetempo==8*minutos)
            {
                diversao=1;
                
            }
            if(contadordetempo==11*minutos)
            {
                terapia=1;
               
            }
            if(contadordetempo==14*minutos)
            {
                diversao=1;
                
            }
        
        //parte gráfica:
        BeginDrawing();
           ClearBackground(WHITE);
           DrawTexture(Quartotx,0,0,RAYWHITE);
           //DrawTexture(circulo1.posicaox,circulo1.posicaoy,RAYWHITE);
           //DrawTextureRec(Texture2D texture, Rectangle sourceRec, Vector2 position, Color tint); 
           DrawText(TextFormat("x: %i y: %i",x,y),10,15,40,RED);
           DrawText(TextFormat("Memoria: %i",memoria),16,717,40,BLACK);
           DrawText(TextFormat("Stress: %i Estabilidade: %i",stress,estabilidade),450,273,38,BLACK);
           DrawText(TextFormat("Fase 1"),629,94,35,BLACK);
           DrawText(TextFormat("Tempo: %i", contadordetempo),1115,42,35,BLACK);
           //DrawTextureRec(Karoltx,Karolrec,Karolp,RAYWHITE);
           //DrawTextureRec(Guilhermetx,Guilhermerec,Guilhermep,RAYWHITE);
           
           // desenhando memórias:
           if(desenharmemoria[0]==1)
           {
              DrawTextureRec(memoriastx,memoriasrec,memoriasp,RAYWHITE); 
           }
           if(desenharmemoria[1]==1)
           {
              DrawTextureRec(memoriastx,memoriasrec,memoriasp2,RAYWHITE);
           }
           if(desenharmemoria[2]==1)
           {
              DrawTextureRec(memoriastx,memoriasrec,memoriasp3,RAYWHITE);
           }
           if(desenharmemoria[3]==1)
           {
              DrawTextureRec(memoriastx,memoriassadrec,memoriaspsad1,RAYWHITE);
           }
           if(desenharmemoria[4]==1 && contadordetempo >= 3600)
           {
              DrawTextureRec(monstrotx,monstrorec,conflitop,RAYWHITE);
           }
           //desenhando desafio:
           if(desafio==1)
           {
               
               if(batalha>=1)
               {
                   batalhafuncao2(falatx,&ruim,&batalha);
                   
               }
               if(batalha==0)
               {
                   desenharmemoria[4]=0;
                   conflito.x=0;
                   conflito.y=0;
                   
               }
               if(batalha==0 && ruim<=0)
               {
                   if(desenharmemoria[5]==1)
                   {
                      DrawTextureRec(memoriastx,memoriasrec,memoriap4,RAYWHITE); 
                   }
                  
                 
               }    
               else if(batalha==0 && ruim>0)
               {
                   if(desenharmemoria[5]==1)
                   {
                      DrawTextureRec(memoriastx,memoriassadrec,memoriap4,RAYWHITE);
                   }
                   
               }
               
           }
           //diversao e terapia:
           if(diversao==1)
           {
               diversaoaviso(falatx);
           }
           if(terapia==1)
           {
               terapiaaviso(falatx);
           }
           int espera = 1400;
           if(contadordetempo>=(1*minutos)+espera && contadordetempo<(1*minutos)) 
           {
               desenhar=1;
           }
           if(contadordetempo>=(1*minutos)+espera && contadordetempo<(3*minutos))
           {
               desenhar=1;
           }
           if(contadordetempo>=(1*minutos)+espera && contadordetempo<(6*minutos))
           {
               desenhar=1;
           }
           if(contadordetempo>=(1*minutos)+espera && contadordetempo<(9*minutos))
           {
               desenhar=1;
           }
           if(desenhar==1)
           {
               DrawTextureRec(Jorgetx,Jorgerec,Jorgep,RAYWHITE);
           }
           //CONDIÇÃO PARA SUBIR DE NIVEL, POR FAVOR LEMBRAR DE ALTERAR ISSO KK SE NÃO ELE VAI SUBIR DE LEVEL FACIL KKKK
           if(estabilidade => 14){
                int tantoFaz = subiu_de_level(&checkpoint);
           }
           
        EndDrawing();
    }
    CloseWindow();
    
}// fim de tudo

void move_circ(int* posic){
    if(IsKeyPressed(KEY_UP))
    {
        if((*posic) > 420)
        {
            (*posic) -= 50;
        }
    }
    if(IsKeyPressed(KEY_DOWN))
    {
        if((*posic) < 600)
        {
            (*posic) += 50;
        }
    }
}

void menu(){
        
        int posic_circ = 470;
        Image Menu = LoadImage("/jogoip/menu.png");
        ImageResize (&Menu,1366,788);
        Texture2D Menutx = LoadTextureFromImage(Menu);
        
    while(!WindowShouldClose()){
        
        BeginDrawing();
               ClearBackground(RAYWHITE);
               DrawTexture(Menutx,0,0,RAYWHITE);
               int x = GetMouseX();
               int y = GetMouseY();
               DrawText(TextFormat("x: %i y: %i",x,y),10,15,40,RED);
               DrawText("Fase 1",600,450,50,BLACK);
               DrawText("Fase 2",600,500,50,BLACK);
               DrawText("Fase 3",600,550,50,BLACK);
               DrawText("Sobre nós",600,600,50,BLACK);
               DrawCircle(580,posic_circ,10,RED);
               move_circ(&posic_circ);
               
        int opcMenu = 0;
        
        int checkpoint = qual_level(0);
        
        if (posic_circ == 470 && IsKeyPressed(KEY_ENTER)){
            opcMenu = 1;
        }else if ((posic_circ == 520 && IsKeyPressed(KEY_ENTER)) && checkpoint >= 2){
            opcMenu = 2;
        }else if ((posic_circ == 570 && IsKeyPressed(KEY_ENTER)) && checkpoint >= 3){
            opcMenu = 3;
        }else if (posic_circ == 620 && IsKeyPressed(KEY_ENTER)){
            opcMenu = 4;
        }
        EndDrawing();
        switch(opcMenu){
            case 1 : 
                tudoDoJorge();
                break;
            //end case 1
            case 2 : 
                CloseWindow();
                break;
            //end case 2
            case 3 : 
                CloseWindow();
                break;
            //end case 3
            case 4 : 
                CloseWindow();
                break;
            //end case 4
        }//end switch
    }//end window should close
}// end função menu 

//Verificar qual level a pessoa está e atribuir a um int check
int qual_level(int checkpoint){
     //PARA O ARMAZENAMENTO (LER)
    FILE *level;
    level = fopen("checkpoint.txt" , "r");
    //Variavel aonde estará armazenado em qual fase ele está
    int levelum = 0, leveldois = 0, leveltres = 0;
    //Função que escreve do arquivo (.txt) e passa para as variaveis levelum, leveldois, leveltres
    fscanf(level, "%i %i %i", &levelum, &leveldois, &leveltres);
    //Função para parar de ler o arquivo
    fclose(level);
    //Caso o jogador só tenha o primeiro level desbloqueado
    int check = levelum + leveldois + leveltres;
    if(check == 1){
        return checkpoint = 1;
    }
    //Caso o jogador tenha os dois primeiros level desbloqueado
    if(check == 2){
        return checkpoint = 2;
    }
    //Caso o jogador tenha os três primeiros level desbloqueado
    if(check == 3){
        return checkpoint = 3;
    }
}

int subiu_de_level(int* checkpoint){
    //ESCREVENDO NO ARQUIVO (checkpoint.txt)
    FILE *level;
    level = fopen("checkpoint.txt" , "w");
    //Variaveis criadas no escopo dessa função
    int check = qual_level(&checkpoint);
    //Se a função for chamada quando o checkpoint = 1; será escrito no arquivo checkpoint.txt 1 1 0
    if(check == 1){
        fprintf("checkpoint.txt" , "1 1 0");
    }
    //Se a função for chamada quando o checkpoint = 2; será escrito no arquivo checkpoint.txt 1 1 1
    if(check == 2){
        fprintf("checkpoint.txt" , "1 1 1");
    }
    fclose(level);
    return 0;
}//end subiu

int main(void)
{
    const int screenWidth = 1366; 
    const int screenHeight = 768;
     
    InitWindow(screenWidth, screenHeight, " Pixelmind ");

    SetTargetFPS(60);    
    
    menu();
    
    return 0;
}