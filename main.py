from PyQt5 import uic, QtWidgets, QtGui
from pyautogui import hotkey

class notepad(QtWidgets.QMainWindow):
    def __init__(self):
        super(notepad, self).__init__()
        uic.loadUi(r"janelas\notepad.ui", self)
        
        self.question = lambda: QtWidgets.QMessageBox.question(self, 'Notepad', 'Deseja salvar as alterações?', QtWidgets.QMessageBox.Save | QtWidgets.QMessageBox.Discard | QtWidgets.QMessageBox.Cancel)
        
        self.setWindowTitle("Sem título - Notepad")
        self.texto.textChanged.connect(self.window_name)
        self.current_file = None

        # Conectando os sinais
        self.actionSalvar_como.triggered.connect(self.salvar_como)
        self.actionAbrir.triggered.connect(self.abrir)
        self.actionSalvar.triggered.connect(self.salvar)
        self.actionSair.triggered.connect(lambda: self.close())
        self.actionNova_Janela.triggered.connect(lambda: notepad_window.show())
        self.actionNovo.triggered.connect(self.novo)
        
        self.actionLocalizar.triggered.connect(lambda: localizar_window.show())
        
        self.actionFonte.triggered.connect(lambda: fonte_window.show())
        
        # Colocando as funções de hotkey
        self.actionDesfazer.triggered.connect(lambda: hotkey("ctrl", "z"))
        self.actionRecortar.triggered.connect(lambda: hotkey("ctrl", "x"))
        self.actionCopiar.triggered.connect(lambda: hotkey("ctrl", "c"))
        self.actionColar.triggered.connect(lambda: hotkey("ctrl", "v"))
        self.actionExcluir.triggered.connect(lambda: hotkey("del"))
        
        if QtGui.QKeySequence("Ctrl+F") == True: self.actionLocalizar
    
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
        
        self.texto.setText("")
        self.setWindowTitle("Sem título - Notepad")
        self.current_file = None
    
    def nova_janela(self):
        self.nova = notepad()
        self.nova.show()
        
    def salvar_como(self):
        fname = QtWidgets.QFileDialog.getSaveFileName(self, "Salvar Arquivo", "Sem Título", "Documentos de Texto (*.txt)")

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
            
            self.setWindowTitle(self.current_file.split("/")[-1] + " - Notepad")
    
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
            try:
                with open(self.current_file, "r", encoding='utf-8', errors='ignore') as f:
                    if f.read() != self.texto.toPlainText():
                        resposta = self.question()
                        
                        if resposta == QtWidgets.QMessageBox.Save:
                            self.salvar()
                        
                        elif resposta == QtWidgets.QMessageBox.Cancel:
                            event.ignore()
                            return
            except TypeError:
                event.accept()
        
        elif self.texto.toPlainText() != "" and self.windowTitle()[0] == "*":
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

class fonte(QtWidgets.QMainWindow):
    def __init__(self):
        super(fonte, self).__init__()
        uic.loadUi(r"janelas\fonte.ui", self)
        
        # Aplicando o tamanho das fontes
        for n in [*range(8, 13), *range(14, 29, 2), 36, 48, 72]:
            self.tamanho.addItem(str(n))
        self.tamanho.setCurrentIndex(2)
        
        # Colocando o exemplo default
        self.exemplo.setFont(QtGui.QFont(self.fonte.currentText(), int(self.tamanho.currentText())))
        
        # Funções
        self.fonte.currentIndexChanged.connect(self.change_font)
        self.tamanho.currentIndexChanged.connect(self.change_font)
        self.estilo.currentIndexChanged.connect(self.change_font_style)
        
    def change_font(self):
        self.exemplo.setFont(QtGui.QFont(self.fonte.currentText(), int(self.tamanho.currentText())))
        notepad_window.texto.setFont(QtGui.QFont(self.fonte.currentText(), int(self.tamanho.currentText())))
        
    def change_font_style(self):
        estilo = self.estilo.currentText()
        
        match (estilo):
            case "Itálico":
                self.exemplo.setStyleSheet("font-style: italic;")
                notepad_window.texto.setStyleSheet("margin: -200;font-style: italic;")
                
            case "Negrito":
                self.exemplo.setStyleSheet("font-weight: bold;")
                notepad_window.texto.setStyleSheet("margin: -200;font-weight: bold;")
                
            case "Itálico e Negrito":
                self.exemplo.setStyleSheet("font-style: italic; font-weight: bold;")
                notepad_window.texto.setStyleSheet("margin: -200;font-style: italic; font-weight: bold;")
            
            case "Regular":
                self.exemplo.setStyleSheet("")
                notepad_window.texto.setStyleSheet("margin: -200;")
                
class localizar(QtWidgets.QMainWindow):
    def __init__(self):
        super(localizar, self).__init__()
        uic.loadUi(r"janelas\localizar.ui", self)
        
        self.buscar.clicked.connect(self.search)
        self.cancelar.clicked.connect(lambda: self.close())
        
    def search(self):
        if self.checkBox.isChecked():
            if self.up.isChecked():
                p = notepad_window.texto.find(self.word.text(), QtGui.QTextDocument.FindBackward | QtGui.QTextDocument.FindCaseSensitively)
            else:
                p = notepad_window.texto.find(self.word.text(), QtGui.QTextDocument.FindCaseSensitively)
                
        else:
            if self.up.isChecked():
                p = notepad_window.texto.find(self.word.text(), QtGui.QTextDocument.FindBackward)
            else:
                p = notepad_window.texto.find(self.word.text())
                
                
        if not p:
            if not self.around.isChecked():
                QtWidgets.QMessageBox.information(self, "Notepad", f'Não é possível encontrar "{self.word.text()}"')
            else:
                if self.up.isChecked():
                    notepad_window.texto.moveCursor(QtGui.QTextCursor.End)
                else:
                    notepad_window.texto.moveCursor(QtGui.QTextCursor.Start)
                    
                if self.word.text() not in notepad_window.texto.toPlainText():
                    QtWidgets.QMessageBox.information(self, "Notepad", f'Não é possível encontrar "{self.word.text()}"')
        
app = QtWidgets.QApplication([])

notepad_window = notepad()
fonte_window = fonte()
localizar_window = localizar()

notepad_window.show()
app.exec()