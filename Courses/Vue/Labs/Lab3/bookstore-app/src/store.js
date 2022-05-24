import { reactive } from "vue";

import { books } from "./assets/js/books.js";

/* ----- Methods ----- */

function addToWishlist(book) {
  if (canAddToWishlist(book)) {
    const wishlistItem = store.wishlist.find(
      (item) => item.book.ISBN === book.ISBN
    );
    wishlistItem
      ? wishlistItem.amount++
      : store.wishlist.push({ book, amount: 1 });
    book.stock--;
  }
}

function removeToWishlist(book) {
  const wishlistItem = store.wishlist.find(
    (item) => item.book.ISBN === book.ISBN
  );
  wishlistItem.amount == 1
    ? store.wishlist.splice(store.wishlist.indexOf(wishlistItem), 1)
    : wishlistItem.amount--;
  book.stock++;
}

function canAddToWishlist(book) {
  return book.stock >= 1;
}

function handleCheckout() {
  store.wishlist.forEach((wishlistItem) => {
    wishlistItem.book.stock += wishlistItem.amount;
  });
  store.wishlist = [];
}

function getBookPrice(book) {
  return formatPrice(book.price);
}

function getTotalPrice(wishlistItem) {
  return formatPrice(wishlistItem.amount * wishlistItem.book.price);
}

function formatPrice(price) {
  return new Intl.NumberFormat("ar-SA", {
    style: "currency",
    currency: "SAR",
    maximumFractionDigits: 2,
  }).format(price);
}

/* ----- store: Shared (Data and Methods) ----- */

export const store = reactive({
  /* Data */
  books,
  wishlist: [],
  /* Methods */
  addToWishlist,
  removeToWishlist,
  handleCheckout,
  getBookPrice,
  getTotalPrice,
  formatPrice,
});


