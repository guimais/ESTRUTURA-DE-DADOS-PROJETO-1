# 🔧 Gerenciador de Manutenção de Equipamentos de Laboratório

Projeto desenvolvido para a disciplina de Estrutura de Dados (Prática) do curso de Engenharia de Computação da PUC Campinas.

O programa, escrito em C, administra as solicitações de manutenção dos equipamentos do Laboratório de Sistemas Embarcados e Automação. Toda a informação fica armazenada em uma lista simplesmente encadeada, com alocação dinâmica de memória. O projeto não usa vetores, variáveis globais nem funções prontas de ordenação.

## 📋 Dados de cada solicitação

| Campo | Descrição |
|---|---|
| Código da solicitação | Inteiro de 4 dígitos, único na lista |
| Código do equipamento | 3 letras seguidas de 3 dígitos (ex.: OSC023) |
| Nome do equipamento | Até 20 caracteres |
| Prioridade | 1 (alta), 2 (média) ou 3 (baixa) |
| Período | Dias que o equipamento pode ficar parado |

O período aceito depende da prioridade:

| Prioridade | Período permitido |
|---|---|
| 1 | 1 a 7 dias |
| 2 | 1 a 15 dias |
| 3 | 1 a 20 dias |

## ⚙️ Funcionalidades

**1. Inserir solicitação**
Adiciona uma nova solicitação já na posição correta, mantendo a lista ordenada pelo código da solicitação. A ordenação acontece no momento da inserção, sem vetor auxiliar. Códigos repetidos são recusados.

**2. Remover solicitação**
Remove a solicitação pelo código e libera a memória do nó.

**3. Consultar solicitação**
Mostra todos os dados de uma solicitação a partir do código, caso ela exista.

**4. Alterar prioridade e/ou período**
Permite mudar a prioridade e o período de uma solicitação, validando o período de acordo com a nova prioridade.

**5. Exibir ordem de manutenção**
Monta uma nova lista com a ordem em que as manutenções devem ser feitas, seguindo estes critérios:

1. Menor prioridade primeiro (1, depois 2, depois 3)
2. Em caso de empate, menor período
3. Persistindo o empate, menor código de solicitação

A lista principal não é alterada. A lista auxiliar é liberada depois de exibida.

**6. Exibir todas as solicitações**
Lista todas as solicitações na ordem da lista principal, ou seja, por código.

**0. Finalizar**
Libera toda a memória alocada antes de encerrar o programa.

## 📁 Estrutura do projeto

```
.
├── Projeto1.c   # Programa principal com o menu e a interação com o usuário
├── Apoio.c      # Biblioteca com as estruturas e as operações da lista
└── README.md
```

## ▶️ Como compilar e executar

### Code::Blocks

1. Crie um projeto do tipo Console Application em C.
2. Adicione `Projeto1.c` e `Apoio.c` ao projeto.
3. Compile e execute com F9.

### Terminal (GCC)

```bash
gcc Projeto1.c Apoio.c -o gerenciador
./gerenciador
```

Se o `Projeto1.c` inclui o `Apoio.c` diretamente com `#include "Apoio.c"`, compile apenas o arquivo principal:

```bash
gcc Projeto1.c -o gerenciador
```

No Windows, execute `gerenciador.exe`.

## 💡 Exemplo de uso

```
Código da solicitação: 1407
Código do equipamento: OSC023
Nome do equipamento: Osciloscopio
Prioridade: 2
Período: 10
```

## 👥 Integrantes

- Guilherme Carvalho Mais
- Luigi Lima
