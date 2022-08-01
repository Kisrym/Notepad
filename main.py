from PyQt5 import uic, QtWidgets
import os

app = QtWidgets.QApplication([])
notepad = uic.loadUi(r"janelas\notepad.ui")
save_window = uic.loadUi(r"janelas\salvar.ui")
open_window = uic.loadUi(r"janelas\abrir.ui")

def salvar():
    save_window.show()
    save_window.setFixedSize(691, 69)
    
    dir_path = os.getcwd()
    if save_window.lineEdit.text() != "":
        dir_path = save_window.lineEdit.text()
        
    save_window.lineEdit.setPlaceholderText(dir_path)
    
    ## Funções
    def salvar_arquivo():
        try:    
            with open(f"{dir_path}\\{save_window.Nome.text()}.txt" if save_window.Nome.text() != "" else f"{dir_path}\\{'Sem Título'}.txt", "w") as f:
                f.write(notepad.texto.toPlainText())
            
            # Limpando os inputs
            save_window.Nome.setText("")
            save_window.lineEdit.setText("")
            
            # Fechando a janela
            save_window.close()
            
        except FileNotFoundError:
            save_window.lineEdit.setText("")
            save_window.lineEdit.setPlaceholderText("Diretório não encontrado")
    
    def cancelar():
        save_window.close()
        save_window.lineEdit.setText("")
    
    ## Conectando os botões
    save_window.pushButton.clicked.connect(salvar_arquivo)
    save_window.pushButton_2.clicked.connect(cancelar)

def abrir():
    open_window.show()
    open_window.setFixedSize(691, 69)
    
    ## Funções
    def abrir_arquivo():
        with open(f"{open_window.lineEdit.text()}", "r") as f:
            notepad.texto.setText(f.read())
        
        open_window.close()
    def cancelar():
        open_window.close()
        open_window.lineEdit.setText("")
    
    ## Conectando os botões
    open_window.pushButton.clicked.connect(abrir_arquivo)
    open_window.pushButton_2.clicked.connect(cancelar)
    
notepad.Salvar.clicked.connect(salvar)
notepad.Abrir.clicked.connect(abrir)

notepad.show()
notepad.setFixedSize(805, 600)
app.exec()