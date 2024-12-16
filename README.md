# EscolaDoFuturo
# Documentação do Código

## Resumo
Este programa é um sistema para gerenciar notas e frequência de alunos, permitindo o cálculo da média das duas maiores notas, verificação de frequência e um relatório geral que avalia a situação final do aluno. Ele utiliza entradas validadas para garantir a robustez contra dados inválidos.

## Funcionalidades Principais

1. **Média do Aluno**
   - Permite que o usuário insira três notas (AP1, AP2 e AP3).
   - Calcula a média das duas maiores notas e exibe o resultado.

2. **Frequência do Aluno**
   - Recebe o número de dias frequentados (de 0 a 30).
   - Calcula a porcentagem de frequência e indica se ela é suficiente (>= 75%) ou insuficiente (< 75%).

3. **Resultado Geral**
   - Permite ao usuário inserir as notas e o número de dias frequentados.
   - Avalia a situação final do aluno com base na média (≥ 7.0) e na frequência (≥ 75%).

4. **Sair**
   - Permite encerrar o programa.

## Funções e Estrutura

### `float calculateAverage(float grade1, float grade2, float grade3)`
Calcula a média das duas maiores notas, ignorando a menor.

- **Parâmetros**:
  - `grade1`: Nota 1.
  - `grade2`: Nota 2.
  - `grade3`: Nota 3.
- **Retorno**:
  - Média das duas maiores notas (float).

### `bool getInputInt(const char *prompt, int *value, int min, int max)`
Recebe um inteiro validado dentro de um intervalo.

- **Parâmetros**:
  - `prompt`: Mensagem para o usuário.
  - `value`: Ponteiro onde o valor será armazenado.
  - `min`: Valor mínimo permitido.
  - `max`: Valor máximo permitido.
- **Retorno**:
  - `true` se a entrada for válida.

### `bool getInputFloat(const char *prompt, float *value, float min, float max)`
Recebe um valor float validado dentro de um intervalo.

- **Parâmetros**:
  - `prompt`: Mensagem para o usuário.
  - `value`: Ponteiro onde o valor será armazenado.
  - `min`: Valor mínimo permitido.
  - `max`: Valor máximo permitido.
- **Retorno**:
  - `true` se a entrada for válida.

### `main()`
Responsável pelo fluxo principal do programa, com um loop que exibe um menu e executa as opções escolhidas pelo usuário.

- **Opções do Menu**:
  1. Calcula e exibe a média das duas maiores notas.
  2. Calcula e exibe a frequência do aluno.
  3. Exibe um relatório geral do aluno.
  4. Encerra o programa.

## Validações Implementadas

- **Notas**: As notas devem estar no intervalo [0, 10].
- **Frequência**: Os dias frequentados devem estar no intervalo [0, 30].
- **Menu**: Aceita apenas opções de 1 a 4.

## Exemplo de Uso

### Entrada de Dados
1. Nome do aluno: `João`.
2. Escolha do menu: `1` (Média do aluno).
3. Matéria: `Matemática`.
4. Notas: `7.5`, `8.0`, `6.0`.

### Saída
```
A média das duas maiores notas em Matemática é: 7.75
```

### Resultado Geral
- Nome: `Ana`.
- Matéria: `Física`.
- Notas: `5.0`, `6.0`, `9.0`.
- Dias de frequência: `28`.

#### Saída:
```
Resultado geral para Física:
Média: 7.50
Frequência: 93%
Situação: Aprovado
```

## Melhorias Futuras
- Adicionar suporte a múltiplos alunos.
- Implementar leitura e gravação de dados em arquivo.
- Melhorar a interface com suporte a menus gráficos.

