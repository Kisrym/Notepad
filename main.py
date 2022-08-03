from PyQt5 import uic, QtWidgets

class notepad(QtWidgets.QMainWindow):
    def __init__(self):
        super(notepad, self).__init__()
        uic.loadUi(r"janelas\notepad.ui", self)
        
        self.current_file = None

        # Conectando os sinais
        self.actionSalvar_como.triggered.connect(self.salvar_como)
        self.actionAbrir.triggered.connect(self.abrir)
        self.actionSalvar.triggered.connect(self.salvar)
        self.actionSair.triggered.connect(lambda: self.close())
        self.actionNova_Janela.triggered.connect(self.nova_janela)
        self.actionNovo.triggered.connect(self.novo)
        
    def novo(self):
        if self.current_file == None and self.texto.toPlainText() != "":
            resposta = QtWidgets.QMessageBox.question(self, 'Bloco de notas', 'Deseja salvar as alterações?', QtWidgets.QMessageBox.Save | QtWidgets.QMessageBox.Discard | QtWidgets.QMessageBox.Cancel)
            
            if resposta == QtWidgets.QMessageBox.Save:
                if self.texto.toPlainText() != "" and self.current_file == None:
                    self.salvar_como()
        
        elif self.current_file != None:
            with open(self.current_file, "r", encoding='utf-8', errors="ignore") as f:
                if self.texto.toPlainText() != f.read():
                    resposta = QtWidgets.QMessageBox.question(self, 'Bloco de notas', 'Deseja salvar as alterações?', QtWidgets.QMessageBox.Save | QtWidgets.QMessageBox.Discard | QtWidgets.QMessageBox.Cancel)
                    
                    if resposta == QtWidgets.QMessageBox.Save:
                        self.salvar()
        
        self.texto.setText("")
        self.current_file = None
    
    def nova_janela(self):
        self.nova = notepad()
        self.nova.show()
        
    def salvar_como(self):
        fname = QtWidgets.QFileDialog.getSaveFileName(self, "Salvar Arquivo", "", "Documentos de Texto (*.txt)")

        if fname[0] != "":
            with open(fname[0], "w") as f:
                f.write(self.texto.toPlainText())
    
    def salvar(self):
        if self.texto.toPlainText() != "" and self.current_file == None:
            self.salvar_como()
        else:
            with open(self.current_file, "w") as f:
                f.write(self.texto.toPlainText())
    
    def abrir(self):
        fname = QtWidgets.QFileDialog.getOpenFileName(self, "Abrir Arquivo", "", "Documentos de Texto (*.txt)")
        
        if fname[0] != "":
            with open(fname[0], "r", encoding='utf-8', errors="ignore") as f:
                self.texto.setText(f.read())
            
            # Salvando o diretório do arquivo
            self.current_file = fname[0]
    
    
    def closeEvent(self, event):
        if self.texto.toPlainText() == "":
            event.accept()
        
        else:
            resposta = QtWidgets.QMessageBox.question(self, 'Bloco de notas', 'Deseja salvar as alterações?', QtWidgets.QMessageBox.Save | QtWidgets.QMessageBox.Discard | QtWidgets.QMessageBox.Cancel)
            
            if resposta == QtWidgets.QMessageBox.Save:
                if self.texto.toPlainText() != "" and self.current_file == None:
                    self.salvar_como()
                elif self.texto.toPlainText() != "": # Se o arquivo não está em branco
                    self.salvar()
                    
                event.accept()
            
            elif resposta == QtWidgets.QMessageBox.Discard:
                event.accept()
                
            elif resposta == QtWidgets.QMessageBox.Cancel:
                event.ignore()

app = QtWidgets.QApplication([])

notepad_window = notepad()

notepad_window.show()
app.exec()