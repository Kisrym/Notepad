from PyQt5 import uic, QtWidgets

class notepad(QtWidgets.QMainWindow):
    def __init__(self):
        super(notepad, self).__init__()
        uic.loadUi(r"janelas\notepad.ui", self)
        
        self.question = lambda: QtWidgets.QMessageBox.question(self, 'Bloco de notas', 'Deseja salvar as alterações?', QtWidgets.QMessageBox.Save | QtWidgets.QMessageBox.Discard | QtWidgets.QMessageBox.Cancel)
        
        self.setWindowTitle("Sem título - Notepad")
        self.texto.textChanged.connect(self.window_name)
        self.current_file = None

        # Conectando os sinais
        self.actionSalvar_como.triggered.connect(self.salvar_como)
        self.actionAbrir.triggered.connect(self.abrir)
        self.actionSalvar.triggered.connect(self.salvar)
        self.actionSair.triggered.connect(lambda: self.close())
        self.actionNova_Janela.triggered.connect(self.nova_janela)
        self.actionNovo.triggered.connect(self.novo)
    
    ## Funções
    def novo(self):
        if self.current_file == None and self.texto.toPlainText() != "":
            resposta = self.question()
            
            if resposta == QtWidgets.QMessageBox.Save:
                if self.texto.toPlainText() != "" and self.current_file == None:
                    self.salvar_como()
            
            elif resposta == QtWidgets.QMessageBox.Cancel:
                return
        
        elif self.current_file != None:
            with open(self.current_file, "r", encoding='utf-8', errors="ignore") as f:
                if self.texto.toPlainText() != f.read():
                    resposta = self.question()
                    
                    if resposta == QtWidgets.QMessageBox.Save:
                        self.salvar()
                    
                    elif resposta == QtWidgets.QMessageBox.Cancel:
                        return
        # arrumar
        
        self.texto.setText("")
        self.setWindowTitle("Sem título - Notepad")
        self.current_file = None
    
    def nova_janela(self):
        self.nova = notepad()
        self.nova.show()
        
    def salvar_como(self):
        fname = QtWidgets.QFileDialog.getSaveFileName(self, "Salvar Arquivo", "", "Documentos de Texto (*.txt)")

        if fname[0] != "":
            with open(fname[0], "w") as f:
                f.write(self.texto.toPlainText())
                
        self.setWindowTitle(fname[0].split("/")[-1] + " - Notepad")
        self.current_file = fname[0]
    
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
            self.setWindowTitle(fname[0].split("/")[-1] + " - Notepad")
    
    ## Eventos
    def closeEvent(self, event):
        if self.texto.toPlainText() == "":
            with open(self.current_file, "r", encoding='utf-8', errors='ignore') as f:
                if f.read() != self.texto.toPlainText():
                    resposta = self.question()
                    
                    if resposta == QtWidgets.QMessageBox.Save:
                        self.salvar()
                    
                    elif resposta == QtWidgets.QMessageBox.Cancel:
                        event.ignore()
                        return
        
        else:
            resposta = self.question()
            
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
    
    # Muda o nome da janela
    def window_name(self):
        if self.windowTitle()[0] != "*" and self.texto.toPlainText() != "":
            self.setWindowTitle(f"*{self.windowTitle()}")
        elif self.texto.toPlainText() == "" and self.current_file == None:
            self.setWindowTitle(self.windowTitle()[1:])
            

app = QtWidgets.QApplication([])

notepad_window = notepad()

notepad_window.show()
app.exec()