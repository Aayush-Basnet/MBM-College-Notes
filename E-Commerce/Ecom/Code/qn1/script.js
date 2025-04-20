// Define an array to store products
let products = [];

// Function to add a product
function addProduct() {
    const productName = document.getElementById("productName").value;
    const productPrice = document.getElementById("productPrice").value;
    const productDescription = document.getElementById("productDescription").value;

    if (productName && productPrice && productDescription) {
        const product = {
            name: productName,
            price: productPrice,
            description: productDescription
        };

        products.push(product);
        displayProducts();
        
        // Clear input fields
        document.getElementById("productName").value = "";
        document.getElementById("productPrice").value = "";
        document.getElementById("productDescription").value = "";
    } else {
        alert("Filling in all field is mandatory.");
    }
}

// Function to display products
function displayProducts(filteredProducts = products) {
    const productsList = document.getElementById("products");
    productsList.innerHTML = "";

    for (let i = 0; i < filteredProducts.length; i++) {
        const product = filteredProducts[i];
        const li = document.createElement("li");
        li.innerHTML = `<strong>${product.name}</strong><br>Price: NRs.${product.price}<br>${product.description}`;
        productsList.appendChild(li);
    }
}

// Function to search products by name
function searchProducts() {
    const searchInput = document.getElementById("searchInput").value.toLowerCase();
    const filteredProducts = products.filter(product => product.name.toLowerCase().includes(searchInput));
    displayProducts(filteredProducts);
}