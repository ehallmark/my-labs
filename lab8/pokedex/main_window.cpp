#include "main_window.h"

MainWindow::MainWindow()
{
	// Title
	setWindowTitle("Pokedex");



	// Overall layout
	overallLayout = new QHBoxLayout();




	// // Selected pokemon display
	// Layout
	pokemonDisplayLayout = new QVBoxLayout();
	overallLayout->addLayout(pokemonDisplayLayout);

	// Pokemon image
	//TODO
	// Set up imageContainer
	pokemonImageContainer = new QLabel();
	pokemonDisplayLayout->addWidget(pokemonImageContainer);

	// Pokemon name
	//TODO
	pokemonNameDisplay = new QLabel("No Pokemon to Show."); 
	pokemonDisplayLayout->addWidget(pokemonNameDisplay);

	// Make it so image and name are at the top
	pokemonDisplayLayout->addStretch();




	// // List of all pokemon
	//TODO
	pokemonListWidget = new QListWidget();
	overallLayout->addWidget(pokemonListWidget);
    connect(pokemonListWidget, SIGNAL(currentRowChanged(int)), 
            this, SLOT(displayPokemon(int)));



	// // Form to add pokemon
	// Layout
	formLayout = new QVBoxLayout();
	overallLayout->addLayout(formLayout);

	// Pokemon name label
	pokemonNameLabel = new QLabel("Pokemon's Name:");
	formLayout->addWidget(pokemonNameLabel);

	// Pokemon name input
	//TODO
	pokemonNameInput = new QLineEdit();
	formLayout->addWidget(pokemonNameInput);

	// Image filename label
	imageFilenameLabel = new QLabel("Image Filename:");
	formLayout->addWidget(imageFilenameLabel);

	// Image filename input
	//TODO
	imageFilenameInput = new QLineEdit();
	formLayout->addWidget(imageFilenameInput);

	// Add button
	//TODO
	addButton = new QPushButton("Add Pokemon");
	connect(addButton, SIGNAL(clicked()), this, SLOT(addPokemon()));
	formLayout->addWidget(addButton);

	// Set overall layout
	setLayout(overallLayout);
}

MainWindow::~MainWindow()
{
	// Delete the images
	for(std::vector<QImage*>::iterator i = pokemonImages.begin();
		i != pokemonImages.end();
		++i)
	{
		delete *i;
	}


	//TODO the delete UI objects
	delete addButton;
	delete imageFilenameInput;
	delete imageFilenameLabel;
	delete pokemonNameInput;
	delete pokemonNameLabel;
	delete pokemonImageContainer;
	delete pokemonDisplayLayout;
	delete pokemonNameDisplay;
	delete pokemonListWidget;
	delete formLayout;
	delete overallLayout;

}



void MainWindow::addPokemon()
{
	// Do nothing if user left at least one input blank
	//TODO
	if (!((imageFilenameInput->text()).size() && (pokemonNameInput->text()).size())) { 
		return;
	}

	// // Get form values
	// Pokemon name
	//TODO
	QString newName = pokemonNameInput->text();
	pokemonNames.push_back(newName.toStdString());

	
	// Image
	QString filename = imageFilenameInput->text();
	QImage* newImage = new QImage();
	//TODO what should go right here?
	newImage->load(filename);
	pokemonImages.push_back(newImage);


	// Create a new list item with the pokemon's name
	//TODO

	pokemonListWidget->addItem(pokemonNameInput->text());

	// Clear the form inputs
	//TODO
	pokemonNameInput->setText("");
	imageFilenameInput->setText("");
}



void MainWindow::displayPokemon(int pokemonIndex)
{
	// Get the pokemon specified by the index,
	// which is passed into the function when
	// the user clicks on pokemonListWidget

	// Image
	//TODO

	QImage* image = pokemonImages[pokemonIndex];
	pokemonImageContainer->setPixmap(QPixmap::fromImage(*image));

	// Pokemon name
	//TODO
	pokemonNameDisplay->setText(QString::fromStdString(pokemonNames[pokemonIndex]));

}
