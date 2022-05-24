<template>
  <img
    :src="book.image"
    class="card-img-top align-self-center"
    :alt="book.title"
  />
  <span
    class="bg-secondary text-light text-center"
    style="letter-spacing: 0.5rem"
  >
    {{ book.ISBN }}
  </span>
  <div class="card-body">
    <h5 class="card-title">
      <span class="badge rounded-pill bg-success me-2">
        {{ book.category }}
      </span>
      <span>{{ book.title }}</span>
    </h5>
    <p class="card-text">{{ book.summary }}</p>
    <p class="badge bg-info me-1">By: {{ book.author }}</p>
    <p :class="`${book.noOfPages > 50 ? 'badge bg-warning' : 'badge bg-dark'}`">
      {{ book.noOfPages }} pages
    </p>
    <br />
    <p class="badge bg-secondary text-center">
      <span :class="`${!book.stock ? 'text-decoration-line-through' : ''}`"
        >Price: {{ getBookPrice(book) }}, Stock: {{ book.stock }}</span
      >
    </p>
    <br />
    <button @click="addToWishlist(book)" class="btn btn-primary w-100">
      Add to wishlist
    </button>
  </div>
</template>

<script>
import { store } from "../store.js";

const { getBookPrice, formatPrice, addToWishlist } = store;

export default {
  props: {
    book: Object,
  },
  methods: {
    getBookPrice,
    formatPrice,
    addToWishlist,
  },
};
</script>