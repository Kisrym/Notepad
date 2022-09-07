# Versão Python


## Requisitos

Para rodar o projeto, é necessário:

* Python 10+
* PyQt5
* Pyautogui

## Criação de executável

Para criar um executável para o programa, é necessário primeiramente do módulo `pyinstaller`, que pode ser facilmente instalado usando o pip:

`pip install pyinstaller`

Depois disso, use o pyinstaller no arquivo **main.py**: `<br />`

`pyinstall main.py`

Por último, quando o pyinstaller terminar o processo, cole o seguinte código no cmd no diretório do **main.py**: `<br />`

`mv .\janelas\ dist\main\`

E Pronto! O Executável estará na pasta **dist**, basta criar um atalho para onde você quer ele.
